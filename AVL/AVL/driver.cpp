// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: driver.cpp
// Date 11/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/


// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "Node.h"  
#include "avltree.h"
using namespace std;
using namespace Node_1;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

int get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


int main( )
{
    avltree tree; // A sequence that we’ll perform tests on
	Node * r = NULL;
		
	
	

    char choice;   // A command character entered by the user
    
    cout << "Lets play with trees.  What would you like to do first?" << endl;

    do
    {
		r = tree.getroot();
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'P': tree.print(r, 0);
                      break;
            case 'I': tree.insert(r,get_number());
                      break;
            case 'Q': cout << "That's what I was hoping you'd do." << endl;
                      break;
			case 'R': cout << "The tree has been rebalanced" << endl;
					  break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
	cout << endl; // Print blank line before the menu
    cout << " P   Print a copy of the entire sequence" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " Q   Quit this test program" << endl;
	cout << " R   Rebalance the tree"<< endl;

}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

int get_number( )
// Library facilities used: iostream
{
    int d;
    
    cout << "Please enter a number: ";
    cin  >> d;
    cout << d << " has been read." << endl;
    return d;

}