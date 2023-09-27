#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping ::menu()
{
m:
    int choice;
    int id;
    int password;

    cout << "\t\t\t\t____________________\n";
    cout << "\t\t\t\t                    \n";
    cout << "\t\t\t\t  ***Main menu***  \n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t\t\t____________________\n";
    cout << "\t\t\t\t                            \n";
    cout << "\t\t\t\t| 1) Administrator |\n";
    cout << "\t\t\t\t| 2) Buyer         |\n";
    cout << "\t\t\t\t| 3) Exit          |\n";
    cout << "\t\t\t\t Please Select User Type\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t Please Login\n";
        cout << "\t\t\t Enter Admin id\n";
        cin >> id;
        cout << "\t\t\t Enter Password \n";
        cin >> password;
        if (id== 1001 && password ==4848)
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email or Password \n";
        }
        break;
    }

    case 2:
    {
        buyer();
        break;
    }

    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select from given option \n";
    }
    }
    goto m;
}

void shopping ::administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t_______________________";
    cout<<"\n\t\t\t|___1) Add Product____|";
    cout<<"\n\t\t\t|                     |";
    cout<<"\n\t\t\t|___2) Modify_________|";
    cout<<"\n\t\t\t|                     |";
    cout<<"\n\t\t\t|___3) Delete Product_|";
    cout<<"\n\t\t\t|                     |";
    cout<<"\n\t\t\t|____4) Main Menu_____|";
    cout<<"\n\t\t\t|_____________________|";

    cout<<"\n\n\t Please input :";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"Invalid Choice!!!";


    }
 goto m;
} 

void shopping ::buyer(){
    m:
    int choice;
    cout<<"\t\t\t Hello Buyer\n";
    cout<<"\t\t\t_______________\n";
    cout<<"\t\t\t|             |\n";
    cout<<"\t\t\t|1)Buy Product|\n";
    cout<<"\t\t\t|2)Go Back____|\n";
    cout<<"\t\t\t|_____________|\n";
    
    cin>>choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid Choice\n";
        break;
    }
 goto m;

}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t\t\t Product Code : ";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the product :";
    cin>>pname;
    cout<<"\n\n\t\t\t Price :";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on product :";
    cin>>dis;
//to accsess the data base of items
    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;

        }
        data.close();
    }
    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    
        cout<<"\n\n\t\t Record Inserted";


}

void shopping::edit(){

    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Enter Product code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record Edited !";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0){
        cout<<"\n\n Record not found Sorry!";
    }
}

void shopping :: rem(){

    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\t\t Delete Product";
    cout<<"\nt\t\t Product Code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File Doesn't Exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product Deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; 
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not Found";
        }
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________|\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________|\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt(){
    
    fstream data;

    int arrc[100];
    int arrq[100];
    int choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nEmpty Database";
    }

    else{
        data.close();


        list();
        cout<<"\n__________________________________\n";
        cout<<"\n|                                |\n";
        cout<<"\n|      Please Place Order        |\n";
        cout<<"\n|                                |\n";
        cout<<"\n|________________________________|\n";

        do{
            m:
            cout<<"\n\nEnter Product Code :";
            cin>>arrc[c];
            cout<<"\n\nEnter Product quantity";
            cin>>arrq[c];
            
            for(int i=0;i<c;i++){

                if(arrc[c]==arrc[i]){

                    cout<<"\n\n Duplicate Product Code . Please Try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to buy another product? ";
           cout<<"For Yes press 1 else 2 for no";
            cin>>choice;
             if(choice==2){
                break;
            }

        }
        while(choice == 1);


        cout<<"\n\n\t\t\t_______________RECEIPT_______________";
        cout<<"\nProduct No.\t Product Name\tProduct Quantity\tPrice\tAmount\tAmount with Discount\n";
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();


    }
    cout<<"\n\n_____________________________________";
    cout<<"\n Total Amount :"<<total;


}

int main(){
    shopping s;
    s.menu();
}
