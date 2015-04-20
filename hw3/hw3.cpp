#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{

    double xo,xi,s,yo=0,yi,xn,yn=0;
    ofstream openfile;
    openfile.open("hw3.csv");

    cout<<left<<setw(15)<<"s"<<left<<setw(15)<<"x[o]=fo(s)"<<left<<setw(15)<<"x[i]=f(s)"<<endl;
    openfile<<"s,xo=fo(s),xi=f(s),xn,yo,yi,yn"<<endl;
    s=0.000;
    xo=pow(3,s);
    xi=pow(3,s)+sin(10*s);
    xn=xo+((double)rand()*2/RAND_MAX-1);
    yo=0.85*yo+0.15*xo;
    yi=0.85*yi+0.15*xi;
   yn=0.85*yn+0.15*xn;
    cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
    s=0.200;
     xo=pow(3,s);
     xi=pow(3,s)+sin(10*s);
     xn=xo+((double)rand()*2/RAND_MAX-1);
     yo=0.85*yo+0.15*xo;
     yi=0.85*yi+0.15*xi;
    yn=0.85*yn+0.15*xn;
     cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
     s=0.400;
      xo=pow(3,s);
      xi=pow(3,s)+sin(10*s);
      xn=xo+((double)rand()*2/RAND_MAX-1);
      yo=0.85*yo+0.15*xo;
      yi=0.85*yi+0.15*xi;
     yn=0.85*yn+0.15*xn;
      cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
      s=0.600;
       xo=pow(3,s);
       xi=pow(3,s)+sin(10*s);
       xn=xo+((double)rand()*2/RAND_MAX-1);
       yo=0.85*yo+0.15*xo;
       yi=0.85*yi+0.15*xi;
      yn=0.85*yn+0.15*xn;
       cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
       s=0.800;
        xo=pow(3,s);
        xi=pow(3,s)+sin(10*s);
        xn=xo+((double)rand()*2/RAND_MAX-1);
        yo=0.85*yo+0.15*xo;
        yi=0.85*yi+0.15*xi;
       yn=0.85*yn+0.15*xn;
        cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
        s=1.000;
         xo=pow(3,s);
         xi=pow(3,s)+sin(10*s);
         xn=xo+((double)rand()*2/RAND_MAX-1);
         yo=0.85*yo+0.15*xo;
         yi=0.85*yi+0.15*xi;
        yn=0.85*yn+0.15*xn;
         cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
         s=1.200;
          xo=pow(3,s);
          xi=pow(3,s)+sin(10*s);
          xn=xo+((double)rand()*2/RAND_MAX-1);
          yo=0.85*yo+0.15*xo;
          yi=0.85*yi+0.15*xi;
         yn=0.85*yn+0.15*xn;
          cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
          s=1.400;
           xo=pow(3,s);
           xi=pow(3,s)+sin(10*s);
           xn=xo+((double)rand()*2/RAND_MAX-1);
           yo=0.85*yo+0.15*xo;
           yi=0.85*yi+0.15*xi;
          yn=0.85*yn+0.15*xn;
           cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
           s=1.600;
           xo=pow(3,s);
           xi=pow(3,s)+sin(10*s);
           xn=xo+((double)rand()*2/RAND_MAX-1);
           yo=0.85*yo+0.15*xo;
           yi=0.85*yi+0.15*xi;
          yn=0.85*yn+0.15*xn;
           cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
           s=1.800;
           xo=pow(3,s);
           xi=pow(3,s)+sin(10*s);
           xn=xo+((double)rand()*2/RAND_MAX-1);
           yo=0.85*yo+0.15*xo;
           yi=0.85*yi+0.15*xi;
          yn=0.85*yn+0.15*xn;
           cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
           s=2.000;
            xo=pow(3,s);
            xi=pow(3,s)+sin(10*s);
            xn=xo+((double)rand()*2/RAND_MAX-1);
            yo=0.85*yo+0.15*xo;
            yi=0.85*yi+0.15*xi;
           yn=0.85*yn+0.15*xn;
            cout<<setw(15)<<s<<setw(15)<<xo<<setw(15)<<xi<<endl;
openfile<<s<<","<<xo<<","<<xi<<","<<xn<<","<<yo<<","<<yi<<","<<yn<<endl;
   openfile.close();





    return 0;
}
