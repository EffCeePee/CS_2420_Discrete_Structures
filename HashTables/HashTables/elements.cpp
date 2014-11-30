// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: elements.cpp
// Date: 11/26/2013

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


#include "elements.h"


element::element()
{
	key = 0;
	name = "null";
	weight = 0;
	next = NULL;

}


element::element(int k, string n, double w)
{
	key = k;
	name = n;
	weight = w;
	next = NULL;

}
