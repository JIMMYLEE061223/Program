#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int outlook,i,windy,h;
    double humidity,temp;
    string play,olk,win;
    char filename[50];
    cout<<"The following is menu:"<<endl;
    cout<<"(1)=sunny"<<endl;
    cout<<"(2)=overcast"<<endl;
    cout<<"(3)=rainy"<<endl;
    cout<<"(4)=true"<<endl;
    cout<<"(5)=false"<<endl;
    cout<<"please enter the filename to your txt."<<endl;
    cin>>filename;
    ofstream fout;
    fout.open(filename);
    fout<<left<<setw(10)<<"NO."<<setw(10)<<"outlook"<<setw(10)<<"temp"<<setw(10)<<"humidity"<<setw(10)<<"windy"<<setw(10)<<"play"<<endl;

    for(i=0;i<14;i++)
    {
        cout<<"please enter the outlook,temp,humidity,windy"<<endl;
        cin>>outlook>>temp>>humidity>>windy;

        if(humidity<=75.0)   {   h=8; }
        if(humidity>75.0)   {  h=9;}
        switch(outlook){
        case 1:olk="sunny";
            switch(h){
            case 8:cout<<"yes"<<endl;
                play="yes";
                switch(windy){
                case 4:win="true";
                    cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                    break;
                case 5:win="false";
                    cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                    break;
                }
                break;
            case 9:cout<<"no"<<endl;
                play="no";
                switch(windy){
                case 4:win="true";
                    cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                    break;
                case 5:win="false";
                    cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                    break;
                }
                break;
            }
            break;
        case 2:olk="overcast";
            cout<<"yes"<<endl;
            play="yes";
            switch(windy){
            case 4:win="true";
                cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                break;
            case 5:win="false";
                cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                break;
            }
            break;
        case 3:olk="rainy";
            switch(windy){
            case 4:cout<<"no"<<endl;
                play="no";
                win="true";
                cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                break;
            case 5:cout<<"yes"<<endl;
                play="yes";
                win="false";
                cout<<"outlook=="<<olk<<"  temp=="<<temp<<"  humidity=="<<humidity<<"  windy=="<<win<<endl;
                break;
            }
            break;
        }
        fout<<left<<setw(10)<<i+1<<left<<setw(10)<<olk<<setw(10)<<temp<<setw(10)<<humidity<<setw(10)<<win<<setw(10)<<play<<endl;
    }
    fout.close();
    return 0;
}

