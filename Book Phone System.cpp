#include<iostream>
using namespace std;

class contact{      // class for contact details

private:

    // name of the contact and phone
    string contact_name,contact_phone;

public:

    void set_name(){    // Function to set the name of the contacts
        cin>>contact_name;
    }

    void set_number(){ // Function to set the number of the contact
        cin>>contact_phone;
    }

    string get_name(){ // Function to get the name of the contact
        return contact_name;
    }

    string get_number(){ // Function to get the number of the contact
        return contact_phone;
    }
};

// class book_phone
class book_phone:public contact{

private:

    contact book[100];   // array of class contact to store contact details
    int idx=0;           // current index in the array

public:

    void add_contact(){// Function to add contact in the system
        cout<<"\nEnter contact name : ";
        book[idx].set_name();
        cout<<"\nEnter contact number : ";
        book[idx++].set_number(); // increase the index by one
    }

    void search_number(){// Function to search about contact
        string name;
        cout<<"\nEnter the name you want to search about : ";
        cin>>name;
        // search for the name in the book array
        for(int i=0;i<idx;i++){
            if(book[i].get_name()==name){
                cout<<"\n"<<name<<" "<<book[i].get_number();
                return;
            }
        }
    }

    // Function to print all numbers in the book array
    void print(){
        // print all contacts
        for(int i=0;i<idx;i++){
            cout<<"\n "<<book[i].get_name()<<" "<<book[i].get_number();
        }
    }

};

int main(){

    book_phone book; // declare an object of book_phone class
    int type;
    do{
        // the list of what the user could chose
        cout<<"\n\n";
        cout<<"If you want to add a contact to the book    Enter 1 : \n";
        cout<<"If you want to get contact number           Enter 2 : \n";
        cout<<"If you want to print all contacts           Enter 3 : \n";
        cout<<"If you want to close the project            Enter 0 : \n";
        cout<<"\nEnter Your choice : ";
        cin>>type;
        if(type==1){// if the user chose to add contact
            book.add_contact();
        }
        if(type==2){// if the user search a contact number
            book.search_number();
        }
        if(type==3){// if the user chose to print all contacts
            book.print();
        }
    }while(type!=0);

    return 0;
}
