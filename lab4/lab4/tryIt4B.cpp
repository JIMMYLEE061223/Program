// Lab 4 tryIt4B -- Using Boolean Variables and Branching Logic
// Determine what each output statement will print. Then run the
// program to see if you are correct. If any of your answers are
// wrong, figure out why the program produced the output it did.
#include <iostream>
using namespace std;

int main()
{
    bool hungry = true,
         sleepy = false,
         happy = true,
         lazy = false;

    cout << hungry << "  " << sleepy << endl;

    if (hungry == true)
        cout << "I'm hungry. \n";

    if (sleepy == true)
        cout << "I'm sleepy. \n";

    if (hungry)
        cout << "I'm still hungry. \n";
    else
        cout << "I'm not hungry. \n";

    if (sleepy)
        cout << "I'm still sleepy. \n";
    else
        cout << "I'm not sleepy. \n";

    if (sleepy)
        cout << "I'm sleepy. \n";
    else if (lazy)
        cout << "I'm lazy. \n";
    else if (happy)
        cout << "I'm happy. \n";
    else if (hungry)
        cout << "I'm hungry. \n";

    return 0;
}
