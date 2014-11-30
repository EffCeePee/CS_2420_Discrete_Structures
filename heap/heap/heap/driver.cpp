// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: driver.cpp
// Date 11/4/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/


// An interactive test program for the new sequence class

#include <cctype>       // Provides toupper
#include <iostream>     // cout, and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "Heap.h"

using namespace heap_1;
using namespace std;

// PROTOTYPES for functions used by this test program:


void heapSort(int *, int);
// Postcondition: returns a sorted heap 

void populate(int *, int);
// postcondition: populates a small array


void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

int get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

const int arraySize = 10;

int main( )
{
    heap myheap; // A sequence that we’ll perform tests on
	int testArray[arraySize];
	int * ptr = testArray;
		
    char choice;   // A command character entered by the user
    
    cout << "Lets play with a heap.  What would you like to do first?" << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'P': myheap.print();
                      break;
			case 'T': myheap.print_tree(1,myheap.get_size());
					  break;
            case 'I': myheap.insert(get_number( ));
                      break;
	        case 'R': cout << "The first number " << myheap.remove_front() <<" has been removed." << endl;
                      break;
			case 'S': heapSort(ptr, arraySize);
				      break;
            case 'Q': cout << "That's what I was hoping you'd do." << endl;
                      break;
			case '+': populate(ptr, arraySize);
					  cout << "An array was populated with 15 elements." << endl;
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
	cout << " T   Print a copy of the heap in tabbed mode" << endl;
    cout << " S   Perform a heap sort on a random array" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Activate the remove front ( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
	cout << " +   Randomly populate an array with 10 elements" << endl;
}


void heapSort(int *h, int size)
{
	heap sortedHeap;

	cout << " The random array" << endl;

	for(int i = 1; i < size; i++)
	{
		sortedHeap.insert(h[i]);
		cout << h[i] << " "; 
	}

	cout << "\n The sorted array" << endl;
	for(int i = 1; i < size; i++)
	{
		h[i] = sortedHeap.remove_front();
		cout << h[i] << " "; 
	}

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

void populate(int * ptr, int arraySize)
{
	for(int i = 1; i < arraySize; i++)
	{
		ptr[i]= rand() % 100 +1;
				
	}
}