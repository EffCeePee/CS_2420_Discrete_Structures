// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: Node.H
// Date 11/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#include <iomanip>


#pragma once

namespace Node_1
{
	struct Node
	{
		// variables
		int data;
		int height;
		Node* left;
		Node* right;
		
		//Postcondition: Node data is initialized
		Node(int);
		~Node();
		void adjust_height();
	};
}