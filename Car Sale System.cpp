#include<iostream>
using namespace std;

class car{  // class about car details

private:
    string Brand;
    int id,model,price;

public:

    void set_id(int ID){// Function to set id
        id=ID;
    }

    void set_brand(){// Function to set the Brand of the car
        cout<<"\nEnter the Brand of the car : ";
        cin>>Brand;
    }

    void set_model(){// Function to set the model of the car
        cout<<"\nEnter the model of the car : ";
        cin>>model;
    }

    void set_price(){// Function to set the price of the car
        cout<<"\nEnter the price of the car : ";
        cin>>price;
    }

    void Get(){// Function to get car details
        cout<<"\n* Id : "<<id<<"\t"<<"Brand : "<<Brand<<"\t"<<"Model : "<<model<<"\t"<<"Price : "<<price;
    }

};

class Car_Sale_System:public car{

private:
    car all_car[150];// Array of the class car
    bool availabe[150];// Array of boolean to check the car available or not

public:

    Car_Sale_System(){// empty constructor
        for(int i=0;i<150;i++){// set all car not available
            availabe[i]=0;
        }
    }

    void add_car(){// function to add new car
        for(int i=0;i<150;i++){
            if(availabe[i]==0){
                all_car[i].set_brand();
                all_car[i].set_model();
                all_car[i].set_price();
                all_car[i].set_id(i);
                availabe[i]=1;          // Make the car available
                return;
            }
        }
    }

    void disp(){// Function to display all available cars
        for(int i=0;i<150;i++){
            if(availabe[i]==1)
                all_car[i].Get();
        }
    }

    void delete_car(){// Function to delete car
        int id;
        cout<<"\nEnter car id you want to delete : ";
        cin>>id;
        availabe[id]=0;// put the car not available
    }

    void modify_car(){// Function to modify car details
        int id;
        cout<<"\nEnter car id you want to modify : ";
        cin>>id;
        if(availabe[id]==0){// In case of the car not available
            cout<<"\nCar not available.";
            return;
        }
        // set the new details of the car
        cout<<"\nEnter new Details.";
        all_car[id].set_brand();
        all_car[id].set_model();
        all_car[id].set_price();
    }

};

int main(){

    Car_Sale_System css; // declare an object of car_sale_system
    int want;
    do{
        // the list of what the user could chose
        cout<<"\n\n";
        cout<<"If you want to add a new car     Enter 1 : \n";
        cout<<"If you want to display all cars  Enter 2 : \n";
        cout<<"If you want to delete car        Enter 3 : \n";
        cout<<"If you want to modify car        Enter 4 : \n";
        cout<<"If you want to close the project Enter 0 : \n";
        cout<<"\nEnter Your choice : ";
        cin>>want;
        if(want==1){// if the user want to add a new car
            css.add_car();
        }
        if(want==2){// if the user want to display all cars
            css.disp();
        }
        if(want==3){// if the user want to delete car
            css.delete_car();
        }
        if(want==4){// if the user want to modify car
            css.modify_car();
        }
    }while(want);

    return 0;
}
