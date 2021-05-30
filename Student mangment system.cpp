#include <iostream>
using namespace std;

class student{  // class about student information

private:
    int id;
    string name,number;

public:
    // empty and parametrize constructor
    student(int ID=0,string Name="",string Number=""){
        id=ID;
        name=Name;
        number=Number;
    }

    void set(){ //to set student details
        cout<<"\n\nPlease, Enter student Id : ";
        cin>>id;
        cout<<"\nPlease, Enter student name : ";
        cin>>name;
        cout<<"\nPlease, Enter student number : ";
        cin>>number;
    }

    int get_id(){//function to return the id of the student
        return id;
    }

    void print(){//function to print student details
        cout<<"\nstudent ID : "<<id;
        cout<<"\nstudent name : "<<name;
        cout<<"\nstudent number : "<<number<<"\n";
    }
};

// class system derived from class student
class system:public student{

private:

    student sys[1000]; //array of class student
    int index=0;        //current index in the array

public:

    void add_student(){// function to add student
        sys[index].set();
        index++;       // increase the index to the next position
    }

    void search_student(){// function to search about student
        int id;
        cout<<"\nPlease, Enter student id : ";
        cin>>id;
        // searching for the student
        for(int i=0;i<index;i++){
            if(sys[i].get_id()==id){
                sys[i].print();
                return; // to return if the name was found
            }
        }
    }

    void print_all(){// function to print all student
        for(int i=0;i<index;i++){
            sys[i].print();
        }
    }

};

int main(){

    int x;
    system s;//declare object from system class
    do{
        cout<<"\nIf you want to add student        Enter 1 : ";
        cout<<"\nIf you want to search student     Enter 2 : ";
        cout<<"\nIf you want to print all students Enter 3 : ";
        cout<<"\nIf you want to exit               Enter 0 : ";
        cout<<"\n\nPlease, Enter your choice : ";
        cin>>x;
        if(x==1){// if the user chose to add student
            s.add_student();
        }
        if(x==2){// if the user chose to search about student
            s.search_student();
        }
        if(x==3){//if the user chose to print all students details
            s.print_all();
        }
    }while(x!=0);//if the user chose to close the program

    return 0;
}
