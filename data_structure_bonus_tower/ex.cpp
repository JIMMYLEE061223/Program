#include <iostream>
using namespace std;
void cmove(int,char,char,char);
int main(void)
{
  int n;
  cin>>n;
  cmove(n,'a','b','c');
  system("pause");
  return 0;
}
void cmove(int n,char a,char b,char c)
{
  static int times=0;
  if(n==1) {
    times++;
    cout<<times<<" times: Move 1 from tower "<<a<<" to "<<c<<endl;
  } else {
    cmove(n-1,a,c,b);
    times++;
    cout<<times<<" times: Move "<<n<<" from tower "<<a<<" to "<<c<<endl;
    cmove(n-1,b,a,c);
  }
}
