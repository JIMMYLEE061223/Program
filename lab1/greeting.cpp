// greeting.cpp
// This program prints a message to greet the user.
#include <iostream>         // Needed to do C++ I/O
#include <string>           // Needed by some compilers to use strings
using namespace std;

int main ()
{
    string name;             // This declares a variable to
    // hold the user's name
    // Get the user's name
    cout << "Please enter your first name: "
    cin  >> name;

    // Print the greeting
    cout << "Hello, " << name << "." << endl;

    return 0;
}
