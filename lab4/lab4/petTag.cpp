// Lab 4 petTag.cpp
// This program determines the fee for a cat or dog pet tag.
// It uses nested if/else statements.
// PUT YOUR NAME HERE.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string pet;         // "cat" or "dog"
    char spayed;        // 'y' or 'n'

    // Get pet type and spaying information
    cout << "Enter the pet type (cat or dog): ";
    cin  >> pet;
    cout << "Has the pet been spayed or neutered (y/n)? ";
    cin  >> spayed;

    // Determine the pet tag fee
    if (pet == "cat")
    {   if (spayed == 'y')
            cout << "Fee is $4.00 \n";
        else
            cout << "Fee is $8.00 \n";
    }
    else if (pet == "dog")
    {   if (spayed == 'y')
            cout << "Fee is $6.00 \n";
        else
            cout << "Fee is $12.00 \n";
    }
    else
        cout << "Only cats and dogs need pet tags. \n";

    return 0;
}
