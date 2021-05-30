#include<bits/stdc++.h>
using namespace std;

class products{

public:
    int id,price;
    string name;

    products(int Id=0,int Price=0,string Name=""){
        id=Id;
        price=Price;
        name=Name;
    };

    void Set(int ID){
        cout<<"\nPlease, Enter Product name : ";
        cin>>name;
        cout<<"\nPlease, Enter Product price : ";
        cin>>price;
        id=ID;
    }

    void Get(){
        cout<<"\nID : "<<id<<"\t"<<"Name : "<<name<<"\t"<<"Price : "<<price;
    }
};

class bill_system:public products{

private:
    products List[100];
    int cnt=1;

public:

    void add_product(){
        cout<<"\nPlease, Enter Product details.\n";
        List[cnt].Set(cnt);
        cnt++;
    }

    void get_products(){
        cout<<"\nProducts : {\n";
        for(int i=1;i<cnt;i++){
            List[i].Get();
        }
        cout << "\n\n}\n";
    }

    void buy_product(){
        get_products();
        int total_money=0,ID;
        while(true){
            cout<<"\nEnter product id or Enter 0 to Exit : ";
            cin>>ID;
            if(ID){
                int Amount=1;
                cout<<"\nEnter product amount : ";
                cin>>Amount;
                total_money+=List[ID].price*Amount;
            }
            else{
                cout<<"\nThe total cost is : "<<total_money<<"\n";
                return;
            }
        }
    }

};
int main() {

    bill_system user;
    int n;
    do{
        cout<<"\nIf you want to add new product Enter 1 : ";
        cout<<"\nIf you want to buy products    Enter 2 : ";
        cout<<"\nIf you want to Exit            Enter 0 : ";
        cout<<"\n\nEnter your choice : ";
        cin>>n;
        if(n==1){
            user.add_product();
        }
        if(n==2){
            user.buy_product();
        }
    }while(n);

    return 0;
}
