// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: iterator.cpp
// Date: 9/10/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/



#include "Iterator.h"

using namespace list_1;


Iterator::Iterator(Node *np)
{
	n = np;
}

void Iterator::operator++()
{
	n=n->next;
}

bool Iterator::is_item()
{
	if(n != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Iterator::operator*()
{
	
	return n->data;
}