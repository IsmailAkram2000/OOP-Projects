#include<bits/stdc++.h>
using namespace std;

class contact{      // class for contact details

private:

    string name,number;     // name of the contact and number

public:
    // empty and parametrize constructor
    contact(string Name="",string Number=""){
        name=Name;
        number=Number;
    }

    void set_name(){    // Function to set the name of the contacts
        cout<<"\nPlease, Enter the contact name : ";
        cin>>name;
    }

    void set_number(){ // Function to set the number of the contact
        cout<<"\nPlease, Enter the contact number : ";
        cin>>number;
    }

    string get_name(){ // Function to get the name of the contact
        return name;
    }

    string get_number(){ // Function to get the number of the contact
        return number;
    }
};

// class for the contact system
class contact_system:public contact{

private:

    contact system[1001]; // array of class contact to store all contact details
    int indx=0;           // current index in the array

public:

    void add_contact(){// Function to add contact in the system
        system[indx].set_name();
        system[indx].set_number();
        indx++;
    }

    void modify_number(){ // Function to modify contact in the system
        string name;
        cout<<"\nPlease, Enter the name you want to modify : ";
        cin>>name;
        // search the name in the system array
        for(int i=0;i<indx;i++){
            if(system[i].get_name()==name){// in case of finding the name modify it then return
                system[i].set_number();
                cout<<"\n\nName was modified successfully";
                return;
            }
        }
        // in case of not finding the name
        cout<<"\n\nName wasn't found";
    }

    void Get_number(){// Function to get number of a contact
        string name;
        cout<<"\nPlease, Enter the name you want to get its number : ";
        cin>>name;
        // searching the name in the system array
        for(int i=0;i<indx;i++){
            if(system[i].get_name()==name){
                cout<<"\n\n"<<name<<" number is "<<system[i].get_number();
                return;
            }
        }
        // In case of not finding the name
        cout<<"\n\nName wasn't found";
    }

    // Function to print all contacts in the system array
    void print_all_contact(){
        if(indx==0){// If there isn't any contact in the system array
            cout<<"\n\nThe system doesn't have any contact yet.";
            return;
        }
        // searching for the contact name
        for(int i=0;i<indx;i++){
            cout<<"\n- "<<system[i].get_name()<<"\t"<<system[i].get_number();
        }
    }

};

int main(){

    contact_system cs; // declare an object of contact_system class
    int choice;
    do{
        // the list of what the user could chose
        cout<<"\n\n";
        cout<<"If you want to add a contact to the system    Enter 1 : \n";
        cout<<"If you want to modify a contact in the system Enter 2 : \n";
        cout<<"If you want to get contact number             Enter 3 : \n";
        cout<<"If you want to print all contacts             Enter 4 : \n";
        cout<<"If you want to close the project              Enter 0 : \n";
        cout<<"\nEnter Your choice : ";
        cin>>choice;
        if(choice==1){// if the user chose to add contact
            cs.add_contact();
        }
        if(choice==2){// if the user chose to modify contact
            cs.modify_number();
        }
        if(choice==3){// if the user chose to get contact number
            cs.Get_number();
        }
        if(choice==4){// if the user chose to print all contacts
            cs.print_all_contact();
        }
    }while(choice);

    return 0;
}
