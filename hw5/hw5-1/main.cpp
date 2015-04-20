#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int rangenum[3][2]={{1001,2999},{1001,2999},{1001,2999}};
int productn,t;
string name,identity,productmodel,purchasedate,address;
string q[3]{"heartrate","bloodpressure","bodyfats"},
a[3]{"smartwatch","sphygmometer","BodyFatMonitor"};
bool test;
char selection1,selection2,selection3,repair,returnpro;
bool productnum(char selection2){

    if(selection2=='r'||selection2=='R')
        t=0;
    else if (selection2=='f'||selection2=='F')
        t=1;
    else if(selection2=='v'||selection2=='V')
        t=2;
    if(productn>rangenum[t][0]&&productn<rangenum[t][1])
        return 1;
    else
    {
        cout<<"we can't find the product number."<<endl;
        return 0;}
}
int main()
{
    cout<<setw(6)<<"Customers log in:"<<endl<<endl;
    cout<<setw(6)<<"Enter your name and identity card"<<endl;
    cin>>name>>identity;
    do{
        cout <<setw(6)<< "Welcome to our Customer Service Center,the following is home menu.Please choose you option: " << endl;
        cout <<setw(6)<< "A.Product usage" << endl;
        cout <<setw(6)<< "B.Product inuqiry" << endl;
        cout <<setw(6)<< "C.Leave system" << endl;
        cin>>selection1;
        if(selection1=='a'||selection1=='A')
        {
            do
            {
                cout<<setw(6)<<"We have three products,which one do you like?"<<endl;
                cout <<setw(6)<< "R." <<a[0]<< endl;
                cout <<setw(6)<< "F." <<a[1]<< endl;
                cout <<setw(6)<< "V." <<a[2]<< endl;
                cout<<setw(6)<<"please enter p to go to the back menu:"<<endl;
                cin>>selection2;
                if(selection2=='p'||selection2=='P')
                    break;
                do
                {
                    cout<<setw(6)<<"Enter your product number:"<<endl;
                    cout<<setw(6)<<"All the product numbers' range are 1001~2999"<<endl;
                    cin>>productn;
                    test=productnum(selection2);
                }while(!test);
                if(selection2=='r'||selection2=='R')
                    cout<<setw(6)<<"Our smartwatch have feature that can measure you heartrate"<<endl;

                if(selection2=='f'||selection2=='F')
                    cout<<setw(6)<<"Our sphygmometer have feature that can measure you blood preasure"<<endl;

                if(selection2=='v'||selection2=='V')
                    cout<<setw(6)<<"Our BodyFatMonitor have feature that can measure you bodyfats"<<endl;

            }while(selection2!='p');
        }
         if(selection1=='b'||selection1=='B'){
            do
            {
                cout <<setw(6)<<"W.Product repair"<<endl;
                cout <<setw(6)<<"K.Product return"<<endl;      //the second menu
                cout <<setw(6)<<"enter p to go to the back menu"<<endl;
                cin  >> selection2;                                                //to hold the second choice
                if(selection2=='p'||selection2=='P')
                    break;
                switch(selection2){
                case 'w':
                    cout <<setw(6)<<"Enter which product model would you like to repair"<<endl;                 //the third menu
                    cout <<setw(6)<<"a."<<a[0]<<endl;
                    cout<<setw(6)<<"b."<<a[1]<<endl;
                      cout <<setw(6)<<"c."<<a[2]<<endl;
                      cout<<setw(6)<<"enter p to back to menu"<<endl;
                    cin  >> selection3;                                                                     //to hold the third choice
                    if(selection3=='p'||selection3=='P')
                        break;
                    do
                    {
                        cout <<setw(6)<<"Enter the productnumber\n";
                        cin  >> productn;
                        test = productnum(selection3);
                    }while(!test);
                    cout <<setw(6)<<"Enter the purchasedate and your address:"<<endl;
                    cin >> purchasedate>>address;
                    srand(5);
                    cout<<setw(6)<<"------------Product repair bill:---------------"<<endl;
                    cout<<setw(6)<<"Your repair number is  "<<rand()<<endl;
                    cout<<setw(6)<<"Your product model is  "<<a[t]<<endl;
                    cout<<setw(6)<<"Your purchase date is  "<<purchasedate<<endl;
                    cout<<setw(6)<<"Your address is  "<<address<<endl;
                    cout<<setw(6)<<"-----------------------------------------------"<<endl;
                    cout<<setw(6)<<"It's our responsibility to reapir our products,so we don't charge any fee from you!"<<endl;
                case 'k':
                    cout <<setw(6)<<"Enter which product model would you like to return"<<endl;                 //the third menu
                    cout <<setw(6)<<"a."<<a[0]<<endl;
                    cout <<setw(6)<<"b."<<a[1]<<endl;
                    cout<<setw(6)<<"c."<<a[2]<<endl;

                    cout<<setw(6)<<"enter p to back to menu"<<endl;
                    cin  >> selection3;                                                                    //to hold the third choice
                    if(selection3=='p'||selection3=='P')
                        break;
                    do
                    {
                        cout <<setw(6)<<"Enter the productnumber"<<endl;
                        cin  >> productn;
                        test = productnum(selection3);
                    }while(!test);
                    cout <<setw(6)<<"Enter the purchase date and your address"<<endl;
                    cin>>purchasedate>>address;
                    srand(6);
                    cout <<setw(6)<<"Your return number: "<< rand() <<endl;
                    cout <<setw(6)<<"Your product model:"<< a[t]<<endl;
                    cout <<setw(6)<<"Your product number:"<< productn <<endl;
                    cout<<setw(6)<<"Your address is  "<<address<<endl;
                    cout <<setw(6)<<"Your purchase date:"<< purchasedate <<endl;

                    break;
                }
            }while(selection2!='p');




        }
        if(selection1 == 'c'||selection1=='C')
            cout <<setw(6)<<"The system will close:"<<endl;
    }while(selection1!='c');
    return 0;
}
