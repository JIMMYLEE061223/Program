// average.cpp
// This program finds the average of two numbers.
// It contains two errors that must be fixed.
#include <iostream>
using namespace std;

int main ()
{
    int size = 0;             // The number of values to be averaged
    double num1,
           num2,
           average;           // Average of num1 and num2

    // Get the two numbers
    cout << "Enter two numbers separated by one or more spaces: ";
    cin  >> num1 >> num2;

    // Calculate the average
    average = num1 + num2 / size;

    // Display the average
    cout << "The average of the two numbers is: " << average << endl;

    return 0;
}
