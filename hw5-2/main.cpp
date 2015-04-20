#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;
int rangenum[3][2]={{1,1000},{1,1000},{1,1000}};
int j,t,a,b,c,p,r,f,v,w,s,na;
string name,identity,productmodel,purchasedate;
string q[3]={"heartrate","bloodpressure","bodyfats"},
z[3]={"smartwatch","sphygmometer","BodyFatMonitor"};
string address[3]={"Taipei","Kaohsiung","Tainan"};
string nam[3]={"John","Jimmy","Tom"};
bool test;
int selection2,returnpro;
bool productnum(int selection2){

    if(selection2==1)
        t=0;
    else if (selection2==2)
        t=1;
    else if(selection2==3)
        t=2;
    if(j>rangenum[t][0]&&j<rangenum[t][1])
        return 1;
    else
    {
        cout<<"we can't find the product number."<<endl;
        return 0;}
}
int main()
{
    int runtimes=100,count;
    int o,k,i,h;
    ofstream openfile;
    openfile.open("hw5-2.txt");
    srand(time(NULL));
    for(count=0;count<runtimes;count++){
        cout<<setw(6)<<"Customers log in:"<<endl<<endl;
        cout<<setw(6)<<"Enter your name and identity card"<<endl;
        na=rand()%3;
        openfile<<"The customer is "<<nam[na]<<",your choices are the following:"<<endl;
        do{
            cout <<setw(6)<< "Welcome to our Customer Service Center,the following is home menu.Please choose you option: " << endl;
            cout <<setw(6)<< "A.Product usage" << endl;
            cout <<setw(6)<< "B.Product inuqiry" << endl;
            cout <<setw(6)<< "C.Leave system" << endl;
            o=rand()%3+1;

            if(o==1)
            {
                openfile<<"a>";
                a++;
                do
                {
                    cout<<setw(6)<<"We have three products,which one do you like?"<<endl;
                    cout <<setw(6)<< "R." <<z[0]<< endl;
                    cout <<setw(6)<< "F." <<z[1]<< endl;
                    cout <<setw(6)<< "V." <<z[2]<< endl;
                    cout<<setw(6)<<"please enter p to go to the back menu:"<<endl;
                    k=rand()%4+1;
                    if(k==4)
                    {
                        openfile<<"p>";
                        p++;
                        break;
                    }
                    do
                    {
                        cout<<setw(6)<<"Enter your product number:"<<endl;
                        cout<<setw(6)<<"All the product numbers' range are 1001~2999"<<endl;
                        j=rand()%100+1;
                        test=productnum(k);
                    }while(!test);
                    if(k==1)
                    {
                        openfile<<"r>";
                        r++;
                        cout<<setw(6)<<"Our smartwatch have feature that can measure you heartrate"<<endl;
                        break;
                    }
                    if(k==2)
                    {
                        openfile<<"f>";
                        f++;
                        cout<<setw(6)<<"Our sphygmometer have feature that can measure you blood preasure"<<endl;
                        break;
                    }
                    if(k==3)
                    {
                        openfile<<"v>";
                        v++;
                        cout<<setw(6)<<"Our BodyFatMonitor have feature that can measure you bodyfats"<<endl;
                        break;
                    }
                }while(k!=4);
            }
            if(o==2){
                openfile<<"b>";
                b++;
                do
                {
                    cout <<setw(6)<<"W.Product repair"<<endl;
                    cout <<setw(6)<<"S.Product return"<<endl;      //the second menu
                    cout <<setw(6)<<"enter p to go to the back menu"<<endl;
                    k=rand()%3+1;                                             //to hold the second choice
                    if(k==3)
                    {
                        openfile<<"p>";
                        p++;
                        break;
                    }
                    switch(k){
                    case 1:
                        openfile<<"w>";
                        w++;
                        cout <<setw(6)<<"Enter which product model would you like to repair"<<endl;                 //the third menu
                        cout <<setw(6)<<"a."<<z[0]<<endl;
                        cout<<setw(6)<<"b."<<z[1]<<endl;
                        cout <<setw(6)<<"c."<<z[2]<<endl;
                        cout<<setw(6)<<"enter p to back to menu"<<endl;
                        i=rand()%4+1;                                                                     //to hold the third choice
                        if(i==4)
                        {
                            openfile<<"p>";
                            p++;
                            break;
                        }
                        do
                        {
                            cout <<setw(6)<<"Enter the productnumber\n";
                            j=rand()%100+1;
                            test = productnum(k);
                        }while(!test);
                        if(i==1)
                        {
                            openfile<<"a>";
                            a++;
                        }
                        if(i==2)
                        {
                            openfile<<"b>";
                            b++;
                        }
                        if(i==3)
                        {
                            openfile<<"c>";
                            c++;
                        }
                        cout <<setw(6)<<"Enter the purchasedate and your address:"<<endl;
                        h=rand()%3;
                        openfile<<endl;
                        openfile<<setw(6)<<"------------Product repair bill:---------------"<<endl;
                        openfile<<setw(6)<<"Your repair number is  "<<rand()%100<<endl;
                        openfile<<setw(6)<<"Your product model is  "<<z[t]<<endl;
                        openfile<<setw(6)<<"Your purchase date is  "<<rand()%14+2000<<"/"<<rand()%12+1<<"/"<<rand()%30+1<<endl;
                        openfile<<setw(6)<<"Your address is  "<<address[h]<<endl;
                        openfile<<setw(6)<<"-----------------------------------------------"<<endl;
                        openfile<<setw(6)<<"It's our responsibility to reapir our products,so we don't charge any fee from you!"<<endl;
                        k=3;
                        break;
                    case 2:
                        openfile<<"s>";
                        s++;
                        cout <<setw(6)<<"Enter which product model would you like to return"<<endl;                 //the third menu
                        cout <<setw(6)<<"a."<<z[0]<<endl;
                        cout <<setw(6)<<"b."<<z[1]<<endl;
                        cout<<setw(6)<<"c."<<z[2]<<endl;
                        cout<<setw(6)<<"enter p to back to menu"<<endl;
                        i=rand()%4+1;                                                                    //to hold the third choice
                        if(i==4)
                        {
                            openfile<<"p>";
                            p++;
                            break;
                        }
                        do
                        {
                            cout <<setw(6)<<"Enter the productnumber"<<endl;
                            j=rand()%100+1;
                            test = productnum(k);
                        }while(!test);
                        if(i==1)
                        {
                            openfile<<"a>";
                            a++;
                        }
                        if(i==2)
                        {
                            openfile<<"b>";
                            b++;
                        }
                        if(i==3)
                        {
                            openfile<<"c>";
                            c++;
                        }
                        cout <<setw(6)<<"Enter the purchase date and your address"<<endl;
                        h=rand()%3;
                        openfile<<endl;
                        openfile<<setw(6)<<"------------Product return bill:---------------"<<endl;
                        openfile <<setw(6)<<"Your return number: "<< rand()%100<<endl;
                        openfile <<setw(6)<<"Your product model:"<< z[t]<<endl;
                        openfile <<setw(6)<<"Your product number:"<< j <<endl;
                        openfile<<setw(6)<<"Your address is  "<<address[h]<<endl;
                        openfile <<setw(6)<<"Your purchase date:"<<rand()%14+2000<<"/"<<rand()%12+1<<"/"<<rand()%30+1<<endl;
                        openfile<<setw(6)<<"-----------------------------------------------"<<endl;
                        k=3;
                        break;
                    }
                }while(k!=3);
            }
            if(o==3)
            {
                openfile<<"c"<<endl<<endl;
                c++;
                cout <<setw(6)<<"The system will close:"<<endl;
            }
        }   while(o!=3);
    }
    cout<<"char a is selected "<<a<<" times"<<endl<<"char b is selected "<<b<<" times"<<endl<<"char c is selected "<<c<<" times"<<endl<<"char r is selected "<<r<<"  times"<<endl<<"char f is selected "<<f<<"  times"<<endl<<"char v is selected "<<v<<"  times"<<endl<<"char p is selected "<<p<<" times"<<endl<<"char w is selected "<<w<<"  times"<<endl<<"char s is selected "<<s<<" times"<<endl;
    cout<<"The time the customers spent were "<<a+b+c+r+f+v+p+w+s<<endl;
    openfile<<endl<<endl;
    openfile<<"Total number of customers visited are 100 people"<<endl;
    openfile<<"char a is selected "<<a<<" times"<<endl<<"char b is selected "<<b<<" times"<<endl<<"char c is selected "<<c<<" times"<<endl<<"char r is selected "<<r<<" times"<<endl<<"char f is selected "<<f<<" times"<<endl<<"char v is selected "<<v<<" times"<<endl<<"char p is selected "<<p<<" times"<<endl<<"char w is selected "<<w<<" times"<<endl<<"char s is selected "<<s<<" times"<<endl;
    openfile<<"The time the customers spent were "<<a+b+c+r+f+v+p+w+s<<endl;
    return 0;
}
