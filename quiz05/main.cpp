#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int seat[4][4];
void Init();
void Show();
bool Available(int row, int col);
void Book(int row, int col);
int main()
{
    int row,col;
    cout<<"This is the now the available seats picture:"<<endl;
    Init();
    Show();
    cout<<"please select which row,col you want to book:"<<endl;
    cin>>row>>col;
    Book(row,col);

              return 0;
}

void Init(){
    int x,y;
    srand(6);
    for(x=0;x<4;x++){
        for(y=0;y<4;y++)
        {
            seat[x][y]=rand()%2;

        }
    }
}
void Show(){
    int x,y;
    for(x=0;x<4;x++){
        for(y=0;y<4;y++){
            cout<<setw(4)<<seat[x][y];
        }
        cout<<endl;
    }
}
bool Available(int row, int col){
    if(seat[row-1][col-1]==0)
    { cout<<"You successfully book the seat."<<endl;
        return 1;}
    else
    { cout<<"Sorry,this seat has been booked"<<endl;
        return 0;
    }
}
void Book(int row, int col){
    bool a;
    a=Available(row,col);
    while(a==0){
         cout<<"please enter again"<<endl;
         cin>>row>>col;
         a=Available(row,col);
}
}

