// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: node.h
// Date: 10/28/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/



#pragma once
#include <iostream>

namespace Node_1
{
	struct Node
	{
		int data;
		Node* left;
		Node* right;

	//Postcondition: Node data is initialized
		Node(int d);
		~Node();
	};
}