// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: Node.cpp
// Date 11/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#include "Node.h"

using namespace Node_1;

Node::Node(int d)
{
		data = d;
		height = 1;
		left = NULL;
		right = NULL;
}

Node::~Node()
{
	
}

void Node::adjust_height()
{
	height++;	
}

