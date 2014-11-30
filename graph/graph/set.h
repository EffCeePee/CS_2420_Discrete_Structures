// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: graph.h
// Date 12/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#pragma once
#include "graph.h"
#include "LL.h"

using namespace list_2;

class set
{
public:
	set();
	~set();

	void insert(int);
	bool is_in(int);

private:
	
	List * l;

};

