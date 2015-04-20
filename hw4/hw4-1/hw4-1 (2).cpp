#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
int i;
double humidity;
    string outlook,temp,windy,sunny,overcast,rainy,play,yes,no;
   cout<<"please enter four factors"<<endl;
   ofstream fout;
   fout.open("hw4.txt");
   fout<<left<<setw(10)<<"NO."<<setw(10)<<"outlook"<<setw(10)<<"temp"<<setw(10)<<"humidity"<<setw(10)<<"windy"<<setw(10)<<"play"<<endl;
   for(i=0;i<14;i++)
 {
  cout<<"please enter the outlook,temp,humidity,windy"<<endl;
  cin>>outlook>>temp>>humidity>>windy;
   if(outlook=="sunny")
   {
       if(humidity<=75.0)
      { cout<<"yes"<<endl;
           play="yes";  }
       else{cout<<"no"<<endl;  play="no";}
   }
   else if(outlook=="overcast")
   {
       cout<<"yes"<<endl;
       play="yes";            }
   else if(outlook=="rainy")
   {
       if(windy=="false")
           {    cout<<"yes"<<endl;  play="yes";}
       else
           {        cout<<"no"<<endl;     play="no";   }
   }
       else
           {      cout<<"wrong"<<endl;  }

   fout<<left<<setw(10)<<i+1<<left<<setw(10)<<outlook<<setw(10)<<temp<<setw(10)<<humidity<<setw(10)<<windy<<setw(10)<<play<<endl;
}

 fout.close();
return 0;
}
