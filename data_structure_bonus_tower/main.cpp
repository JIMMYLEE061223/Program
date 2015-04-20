#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void move(int n,int a,int b,int c);
int main(void)
{
    int n;
    int a=1,b=2,c=3;//tower 1,2,3

    clock_t start,stop;

    cout<<"Enter the plates you want to play Towers of Hanoi:"<<endl;
    cin>>n;
    move(n,a,b,c);

    start=clock(); //紀錄開始計算時間
    for(int i=0;i<1000000*n*n;i++)
    { long s; s=s+i; }
    stop = clock(); //紀錄計算結束時間
    double usetime;
    usetime=((double)stop-(double)start)/CLOCKS_PER_SEC;
    cout << endl << "usetime= " << usetime << "sec." << endl;

    return 0;
}
void move(int n,int a,int b,int c)
{
    static int times=0;
    if(n==1)
    {
        times++;
        cout<<times<<" times: Move 1 from tower "<<a<<" to "<<c<<endl;
    }
    else
    {
        move(n-1,a,c,b);
        times++;
        cout<<times<<" times: Move "<<n<<" from tower "<<a<<" to "<<c<<endl;
        move(n-1,b,a,c);
    }
}
