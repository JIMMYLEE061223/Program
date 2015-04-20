#include <iostream>
#include <fstream>
using namespace std;

double guass[5][6];
double temp[0][0];

void print_data();
void calculate();
int main()
{
    char buffer;
    double ans[4];
    ifstream inputfile;
    inputfile.open("equations.data.txt");

    if(!inputfile)
    {cout<<"failed.";  return 0;}

    //write data in array
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<6;i++)
        {
            inputfile>>guass[k][i];
            inputfile>>buffer;
        }
    }
    inputfile.close();

    //call function and calculate
    print_data();
    calculate();

    //calculate x value
    ans[4]= guass[4][5]/guass[4][4];
    ans[3]=(guass[3][5]-ans[4]*guass[3][4])/guass[3][3];
    ans[2]=(guass[2][5]-ans[4]*guass[2][4]-ans[3]*guass[2][3])/guass[2][2];
    ans[1]=(guass[1][5]-ans[4]*guass[1][4]-ans[3]*guass[1][3]-ans[2]*guass[1][2])/guass[1][1];
    ans[0]=(guass[0][5]-ans[4]*guass[0][4]-ans[3]*guass[0][3]-ans[2]*guass[0][2]-ans[1]*guass[0][1])/guass[0][0];

    cout<<"we can know"<<endl;
    cout<<"X"<<1<<"="<<ans[0]<<endl;
    cout<<"X"<<2<<"="<<ans[1]<<endl;
    cout<<"X"<<3<<"="<<ans[2]<<endl;
    cout<<"X"<<4<<"="<<ans[3]<<endl;
    cout<<"X"<<5<<"="<<ans[4]<<endl;

    return 0;
}

void print_data()
{
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<6;i++)
        {
            cout<<guass[k][i]<<"  ";
        }
        cout<<endl;
    }
    cout<<"next step:"<<endl;
}

void calculate()
{
    double multiple;
    for(int diagonal=0; diagonal<4; diagonal++)
    {
        //if elements in diagonal is 0,change the row to the next one,the value don't change.
        if(guass[diagonal][diagonal]==0)
        {
            for(int column=0;column<6;column++)
            {
                temp[0][0]=guass[diagonal][column];
                guass[diagonal][column]=guass[diagonal+1][column];
                guass[diagonal+1][column]=temp[0][0];
            }
        }
        //multiple the row and subtract to the next row
        for(int row=diagonal+1;row<5;row++)
        {
            multiple=(-1)*(guass[row][diagonal]/guass[diagonal][diagonal]);
            for(int column=diagonal;column<6;column++)
            {
                guass[row][column]=guass[row][column]+(multiple*guass[diagonal][column]);
                guass[row][diagonal]=0;
                //in computer calculation,the term converge to 0 but still little big than 0,
                //actually,in guass law,the term is 0.
            }
        }
        print_data();
    }
}
