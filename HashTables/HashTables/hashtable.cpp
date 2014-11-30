// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: hashtable.cpp
// Date: 11/26/2013

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include "hashtable.h"
#include <cassert>  // Provides assert

using namespace hash_table;

hashtable::hashtable( )
{
	index = 0;
	for (int i = 0; i < CAPACITY; ++i)
	{
		data[i] = new element;
		data[i]->key = NEVER_USED;
	}
}


void hashtable::clear( )
{
for(int i = 0; i < CAPACITY; i++)
	{
		element * head;

		if(data[i]->next != NULL)
		{
			head = data[i]->next;
			data[i]->next = NULL;
			data[i]->key = 0;
			data[i]->name = "null";
			data[i]->weight = 0;
		}

		else if(head != NULL)
		{
			while(head != NULL)
			{
			element * temp = head->next;
			delete head;
			head = temp;
			}
		}
	}

}
void hashtable::insert(const string n, const double w)
{
	index = hash(n);

	if(data[index]->key != NEVER_USED)
	{
		element * ptr = data[index];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		
		ptr->next = new element(index, n, w);

	}
	else
	{
		data[index]->name = n;
		data[index]->weight = w;
		data[index]->key = index;
	}

	index = 0;
}

double hashtable::retrieve(string n)
{
	index = hash(n);

	if(data[index]->name == n)
	{
		return data[index]->weight;
	}
	else if(data[index]->next != NULL)
	{
		element * ptr = data[index]->next;
		
		while(ptr->next != NULL)
		{
			if(ptr->name == n)
			{
				return ptr->weight;
			}
		}
	}

	index = 0;
	
}

int hashtable::hash(string n)
{
	
	for(int i = 0; i < n.length(); i++)
	{
		index += (int)n[i];
	}

	index = index % CAPACITY;

	return index;
}

double hashtable::operator[] (const hashtable& t)
{
	string num = "a";
	return retrieve(num);
}
