// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: hashtable.h
// Date: 11/26/2013

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


#ifndef hashtable_1
#define hashtable_1
#include "elements.h"
#include <string>
#include <iostream>
using namespace std;

namespace hash_table
{
	struct hashtable
	{
		static const int CAPACITY = 193;
		static const int NEVER_USED = -1;
		int index;

		hashtable();
		void clear();
		void insert(const string, const double);
		double retrieve(string);
		int hash(string);

		
		double operator[] (const hashtable&);

		element* data[CAPACITY];


	
	};

}
#endif