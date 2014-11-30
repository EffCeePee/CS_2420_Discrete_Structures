// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: node.cpp
// Date: 10/28/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "Node.h"  
#include "BinTree.h"
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
    bintree tree; // A sequence that we’ll perform tests on
	Node * n = NULL;
		
	n = tree.getptr();
	

    char choice;   // A command character entered by the user
    
    cout << "Lets play with trees.  What would you like to do first?" << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'P': tree.print(n, 0);
                      break;
            case 'S': cout << "Size is " << tree.size(n) << '.' << endl;
                      break;
            case 'I': tree.insert(n, get_number( ));
                      break;
            case 'E': tree.erase(n, get_number());
                      cout << "The node has been removed." << endl;
                      break;     
            case 'Q': cout << "That's what I was hoping you'd do." << endl;
                      break;
			case '-': tree.pre_order(n);
					  break;
			case '0': tree.in_order(n);
				      break;
			case '+': tree.post_order(n);
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
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " E   Activate the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
	cout << " -   Display the tree in pre-order"<< endl;
	cout << " 0   Display the tree in-order" << endl;
	cout << " +   Display the tree in post-order" << endl;
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