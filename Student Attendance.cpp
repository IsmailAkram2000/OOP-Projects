#include <bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int id;
    student(){
        name="";
        id=0;
    }
};

class Attendance{

private:

    string database[1001];
    int att[1001];

public:

    Attendance(){
        for(int i=0;i<=1000;i++){
            database[i]="*";
            att[i]=0;
        }
    }

    void add_student(){
        student s;
        cout<<"\n\nEnter Student Name : ";
        cin>>s.name;
        cout<<"\n\nEnter Student id : ";
        cin>>s.id;
        database[s.id]=s.name;
        cout<<"\n\nStudent successfully added to the database .\n\n";
    }

    void registration(){
        int id;
        cout<<"\n\nPlease, Enter Your id : ";
        cin>>id;
        if(database[id]=="*"){
            cout<<"\n\nThis id doesn't belong to the database \n\n";
        }
        else{
            att[id]=1;
            cout<<"\n\nHello "<<database[id]<<" your register has successfully completed .\n\n";
        }
    }

    void is_att(){
        int id;
        cout<<"\n\nEnter the id you want to check his/her attendance : ";
        cin>>id;
        if(database[id]=="*"){
            cout<<"\n\nThis id doesn't belong to the database : ";
        }
        else if(att[id]==1){
            cout<<"\n\n"<<database[id]<<" has signed his/her Attendance .\n\n";
        }
        else{
            cout<<"\n\n"<<database[id]<<" hasn't signed his/her Attendance .\n\n";
        }
    }

    void all_att(){
        cout<<"\n\n";
        for(int i=0;i<=1000;i++){
            if(database[i]=="*")        continue;
            if(att[i]==1)
                cout<<"- ID : "<<i<<"\t"<<database[i]<<" has signed his/her Attendance .\n\n";
            else
                cout<<"- ID : "<<i<<"\t"<<database[i]<<" hasn't signed his/her Attendance .\n\n";
        }
    }

};

int main(){

    int choice,want;
    Attendance A;
    do{
        cout<<"\n\n* For student             press 1 ";
        cout<<"\n\n* For Doctor              press 2 ";
        cout<<"\n\n* For closing the program press 0 ";
        cout<<"\n\n* Enter your choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"\n* If You want to sign your Attendance Enter 1 :";
            cout<<"\n* If You want to see your attendance  Enter 2 :";
            cout<<"\n\n* Enter your choice : ";
            cin>>want;
            if(want==1){
                A.registration();
            }
            if(want==2){
                A.is_att();
            }
        }
        else if(choice==2){
            cout<<"\n\n* If You want to add new student to the database       Enter 1 :";
            cout<<"\n\n* If You want to check student attendance              Enter 2 :";
            cout<<"\n\n* If you want to see all the attendance of the student Enter 3 :";
            cout<<"\n\n* Enter your choice : ";
            cin>>want;
            if(want==1){
                A.add_student();
            }
            if(want==2){
                A.is_att();
            }
            if(want==3){
                A.all_att();
            }
        }
        else if(choice!=0){
            cout<<"\n\nWrong Choice . \n\n";
        }
        cout<<"\n_______________________________________________________\n";
    }while(choice!=0);

    return 0;
}
