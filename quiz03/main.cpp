#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// quiz03.cpp
// WRITE A COMMENT BRIEFLY DESCRIBING THE PROGRAM.
// PUT Your StudentID and Name HERE.
// Include any needed files here.
int main()
{
    double first,second,third,sum;
    int slices,num1,num2,num3;
    ofstream fout;
    fout.open("bill.txt");

    ifstream fin;
    fin.open("prices.txt");
    fin>>first;
    cout<<"pizza8="<<first<<endl;
    fin>>second;
    cout<<"pizza12="<<second<<endl;
    fin>>third;
    cout<<"pizza16="<<third<<endl;

    cout<<"Please enter the number of each cone type sold that day"<<endl;
    cin>>num1>>num2>>num3;
    cout<<"(The following results should be included to bill.txt)"<<endl;

    cout<<left<<setw(10)<<"Items"<<left<<setw(10)<<"Slices"<<left<<setw(10)<<"Sum of Sales"<<endl;
    fout<<"Items"<<"    "<<"Slices"<<"    "<<"Sum of Sales"<<endl;
    slices=num1;
    sum=num1*first;
    cout<<left<<setw(10)<<"8''pizza"<<left<<setw(10)<<slices<<left<<setw(10)<<sum<<endl;
    fout<<"8''pizza"<<"    "<<num1<<"     "<<sum<<endl;
    slices=num2;
    sum=num2*second;
    cout<<left<<setw(10)<<"12''pizza"<<left<<setw(10)<<slices<<left<<setw(10)<<sum<<endl;
    fout<<"12''pizza"<<"   "<<num2<<"     "<<sum<<endl;
    slices=num3;
    sum=num3*third;
    cout<<left<<setw(10)<<"16''pizza"<<left<<setw(10)<<slices<<left<<setw(10)<<sum<<endl;
    fout<<"16''pizza"<<"   "<<num3<<"     "<<sum<<endl;
    slices=num1+num2+num3;
    sum=num1*first+num2*second+num3*third;
    cout<<left<<setw(10)<<"total"<<left<<setw(10)<<slices<<left<<setw(10)<<sum<<endl;
    fout<<"total"<<"       "<<num1+num2+num3<<"    "<<sum<<endl;
          fin.close();
          fout.close();

// DEFINE NAMED CONSTANTS HERE TO HOLD THE PRICES OF THE 3 SIZES OF PIZZAS.
// GIVE EACH ONE A DESCRIPTIVE NAME AND AN APPROPRIATE DATA TYPE.
//
// DECLARE ALL NEEDED VARIABLES HERE. GIVE EACH ONE A DESCRIPTIVE
// NAME AND AN APPROPRIATE DATA TYPE.
//
// WRITE STATEMENTS HERE TO PROMPT FOR AND INPUT THE INFORMATION
// THE PROGRAM NEEDS TO GET FROM THE USER.
//
// WRITE STATEMENTS HERE TO PERFORM ALL NEEDED COMPUTATIONS.
// AND ASSIGN THE RESULTS TO VARIABLES.
// WRITE STATEMENTS HERE TO DISPLAY THE REQUESTED INFORMATION.
return 0;
}


