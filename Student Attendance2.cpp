#include <iostream>
using namespace std;

class student{  // class for student details

private:
    int number;
    string name;
    bool is_attend;

public:
    // empty and parametrize constructor
    student(int n=0,string Name="",bool bl=false){
        number=n;
        name=Name;
        is_attend=bl;
    }

    void set_number(){ //to set student number
        cout<<"\nPlease, Enter student number : ";
        cin>>number;
    }

    void set_name(){// to set student name
        cout<<"\nPlease, Enter student name : ";
        cin>>name;
    }

    int get_number(){// function to return student number
        return number;
    }

    string get_name(){// function to return student name
        return name;
    }

    void Attend(){// function to attend the current student
        is_attend=true;
    }

    bool chk_attend(){// function to return student attendance
        return is_attend;
    }
};

// class Attendance derived from class student
class Attendance:public student{

private:
    student system[1001]; // array of the class student
    int index=0;          // index to the current position in the array

public:

    void add_student(){// function to add student
        system[index].set_number();
        system[index].set_name();
        index++;       // increase the index to next position
    }

    void attend_student(){// function to attend student
        int num;
        cout<<"\nPlease, Enter student number : ";
        cin>>num;
        // searching for student in the array
        for(int i=0;i<index;i++){
            if(system[i].get_number()==num){
                system[i].Attend();
                cout<<"\n"<<system[i].get_name()<<" has sign his attendance successfully.\n\n";
                return; // to return if the name was found
            }
        }
        // In case of not finding the name
        cout<<"\nNumber doesn't exist \n";
    }

    void check_attendace(){// function to check student attendance
        int num;
        cout<<"\nPlease, Enter student number : ";
        cin>>num;
        for(int i=0;i<index;i++){// searching for student
            if(system[i].get_number()==num){
                if(system[i].chk_attend()){// if the student attend
                    cout<<"\nStudent "<<system[i].get_name()<<" has attend today.\n\n";
                }
                else{//if the student doesn't attend
                    cout<<"\nStudent "<<system[i].get_name()<<" doesn't attend today.\n\n";
                }
                return;//In case of finding student
            }
        }
        //In case of not finding student
        cout<<"\nNumber doesn't exist ";
    }

    void print_student(){//function to print all student in the array
        for(int i=0;i<index;i++){
            if(system[i].chk_attend()){//if the student attend
                cout<<"\n* Student "<<system[i].get_name()<<" has attend today.";
            }
            else{//if the student doesn't attend
                cout<<"\n* Student "<<system[i].get_name()<<" doesn't attend today.";
            }
        }
        cout<<"\n\n";
    }
};

int main(){

    int choice;
    Attendance Att;//declare object of the class Attendance
    do{
        cout<<"\nIf you want to add student              Enter 1 : ";
        cout<<"\nIf you want to attend student           Enter 2 : ";
        cout<<"\nIf you want to check student attendance Enter 3 : ";
        cout<<"\nIf you want to print all student        Enter 4 : ";
        cout<<"\nIf you want to close the program        Enter 0 : ";
        cout<<"\n\nPlease, Enter your choice : ";
        cin>>choice;
        if(choice==1){// if the user chose to add student
            Att.add_student();
        }
        if(choice==2){// if the user chose to attend student
            Att.attend_student();
        }
        if(choice==3){//if the user chose to check student attendance
            Att.check_attendace();
        }
        if(choice==4){// if the user chose to print all student
            Att.print_student();
        }
    }while(choice!=0);//if the user chose to close the program

    return 0;
}
