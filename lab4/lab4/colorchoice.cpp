// This program demonstrates ncurses functions to print colored 
// text. It re-implement color.cpp to show actual color of selection.
#include <iostream>      
#include <ncurses.h>    // Needed to display colors 
using namespace std;

int main()
{
	initscr();			/* Start curses mode 		*/
	start_color();			/* Start color functionality	*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);


	int choice;    // Menu choice should be 1, 2, or 3

	// Display the menu of choices
	attron(COLOR_PAIR(4));
	printw("Choose a primary color by entering its number. \n\n");
	printw("1 Red \n2 Blue \n3 Yellow \n");
        refresh();	// display on screen

	// Get the user's choice
	choice=getch();
	choice=choice-48; //convert ASCII to integer value

	// Tell the user what he or she picked
	if (choice == 1){
	    attron(COLOR_PAIR(1));
	    printw("\nYou picked red.\n");
            refresh();	// display on screen
	}
	else if (choice == 2){
	    attron(COLOR_PAIR(2));
	    printw("\nYou picked blue.\n");
            refresh();	// display on screen
	}
	else{
	    attron(COLOR_PAIR(3));
	    printw("\nYou picked yellow.\n");
            refresh();	// display on screen
	}
     
	printw("Press any key to continue.\n");
	getch(); // Wait for a keyboard input

	endwin();			/* End curses mode		  */
	return 0;
}

