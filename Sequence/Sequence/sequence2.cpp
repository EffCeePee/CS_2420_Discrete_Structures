// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: sequence.cpp
// Date: 9/3/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence2.h"  // With value_type defined as double
using namespace std;
using namespace main_savitch_4;


// default constructor
sequence::sequence(int initial_capacity = DEFAULT_CAPACITY)
{
	capacity = DEFAULT_CAPACITY;
	current_index = 0;
	used = 0;
	int data[DEFAULT_CAPACITY];
	
}



//Copy Constructor
sequence::sequence (const sequence& source)
{
	if ( source.used != NULL)
	{
	    capacity = source.capacity;
		data = new value_type [capacity];
		for (int i = 0; i < capacity; i++)
		{
			this->data[i] = source.data[i];
		}
	}
}

sequence::~sequence(void)
{
	delete [] data;
	data = NULL;
}



void sequence::resize(int new_capacity)
{
	if(used > new_capacity)
	{
		capacity = used;
	}
	else
	{
		capacity = new_capacity;
	}

}

void sequence::start()
{
}

void sequence::advance()
{
}


void sequence::insert(const value_type& entry)
{

	// test to see if there is room to increase the array
	if (capacity == used)
	{

		// double the array variable
		int dbl = 2;

		// double the capacity
		capacity *= dbl;

		// initialize a temp array
		int *temp =  new int [capacity]; 
		
		// copy contents to the new array
		for (int i = 0; i <= used; i++)
		{
			temp[i] = data[i];
		}

		// delete data
		delete [] data;

		// create a new array called data
		data = new value_type [capacity];

		// copy the contents back to my array
		for (int i = 0; i <= used; i++)
		{
			data[i] = temp[i];
		}

		// delete the temporary array
		delete [] temp;

		// assign new value to data
		data[used] = entry;
		used++;
		
	}
	

	else 
	{
		data[used] = entry;
		used++;
	}

}

void sequence::attach (const value_type& entry)
{
}

void sequence::remove_current()
{
}


void sequence::operator= (const sequence& source)

{
	// test for self assignment
	if (this == &source)
	{
		return;
	}

	// clean up array in the left hand object
	delete [] this->data;

	// create new array to hold the array
	capacity = source.capacity;
	this->data = new value_type [capacity];

	// copy the data
	for (int i = 0; i < source.capacity; i++)
	{
		this->data[i] = source.data[i];
	}

	return;

}

int sequence::size() const 
{
}

bool sequence::is_item () const
{
}

value_type sequence::current() const
{
}