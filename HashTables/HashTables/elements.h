// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: elements.h
// Date: 11/26/2013

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


#pragma once
#include <string>

using namespace std;

struct element
{
	int key;
	string name;
	double weight;
	element * next;
	

	// constructor
	element();
	element(int, string, double);

	// overloaded constructor
	element(string, double);

};

