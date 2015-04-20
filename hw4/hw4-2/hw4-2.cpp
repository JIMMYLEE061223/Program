#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int i;
    double humidity;
    char outlook,temp,humidity,windy;

    cout<<"please enter four factors"<<endl;


    ofstream fout;
    fout.open("hw4-2.txt");
    fout<<left<<setw(10)<<"NO."<<setw(10)<<"outlook"<<setw(10)<<"temp"<<setw(10)<<"humidity"<<setw(10)<<"windy"<<setw(10)<<"play"<<endl;
    for(i=0;i<14;i++)
    {
        cout<<"please enter the outlook,temp,humidity,windy"<<endl;
        cin>>outlook>>temp>>humidity>>windy;
        switch(outlook){
        case 'sunny':
            switch(humidity){
            case '>75':cout<<"no"<<endl;
            }





        }
        fout<<left<<setw(10)<<i+1<<left<<setw(10)<<outlook<<setw(10)<<temp<<setw(10)<<humidity<<setw(10)<<windy<<setw(10)<<play<<endl;
    }

    fout.close();
    return 0;
}



