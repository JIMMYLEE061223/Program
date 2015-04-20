#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
   double T1,T2,u,v;
   cin>>u>>v;
   T1=sin(u)+sin(v);
   T2=2*sin((u+v)/2)*cos((u-v)/2);
   cout<< "T1= " <<T1<<setprecision(20)<<endl;
   cout<< "T2= "<<T2<<setprecision(20)<<endl;


   return 0;
}
