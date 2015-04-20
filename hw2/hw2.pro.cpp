#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int sum,sum16,w,x,y,z,a1,a2,b1,b2,c0,c1;
    //unsigned char ;
    float fraction;
    cin>>a1>>a2>>b1>>b2;
    w=(a1*b1)<<16;

    x=(a1*b2)<<8;

    y=(a2*b1)<<8;

    z=a2*b2;
    sum=(w+x+y+z)>>16;
    c0=((w+x+y+z)>>16)>>16;
    cout << c0;

    cout<<"integer="<<c1<<endl;
    sum16=sum<<16;

    c1=sum-(c0<<16);

    fraction=((w+x+y+z)-sum16)*pow(2,-16);
    cout<<"fraction="<<fraction<<endl;
    cout<<"ans="<<(c1+fraction)<<endl;

    return 0;
}


