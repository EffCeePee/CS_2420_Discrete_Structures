// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: avltree.h
// Date 11/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/


#include "Node.h"
#include <iostream>

namespace Node_1
{
	struct avltree
	{
		// variable

		Node * root;
		Node * newRoot;
		
		//Postcondition: Node data is initialized
		avltree();
		~avltree();

		// postcondition: prints out the tree in tabbed form
		void print(Node *, int);

		// postcondition: inserts a node in the proper place in a BST
		//void insert(Node *&, int);
		void insert(Node *, int);

		// postcondition: balances the tree by moving the nodes left around the head node
		Node* rotate_left(Node *);

		// postcondition: balances the tree by moving the nodes right around the head node
		Node* rotate_right(Node *);

		// postcondition: balances the tree by moving the nodes left or right around the head node
		void rebalance(Node *);

		// postcondition: helper condition for the destructor
		void remove_tree(Node *);

		// postcondition: returns the root of the tree;
		Node * getroot();

	};
}