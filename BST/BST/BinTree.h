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

#include "Node.h"


namespace Node_1
{
	class bintree
	{

	private:
		// member variable to define the root of the tree
		Node * root;


	public:

		
		// Postcondition: to initialize the tree
		bintree();

		// Postcondition: to remove the tree
		~bintree();

		// getter function for the pointer
		Node * getptr();

		// clear the tree
		void remove_tree(Node*);

		// postcondition: returns the number of elements in the tree
		int size(Node * n);
		
		// postcondition: print the list in preorder traversal
		//				  One element per line, and indented to the depth
		void print(Node *, int);

		// postcondition: should remove the item with the correct data
		//                then place the other elements in the correct postion
		void erase(Node *&, int);

		// postcondition:  inserts an item into the proper place in the tree,
		//                 no duplicate numbers
		void insert(Node *&, int);

		// traversals

		// prints out in the preorder: self, left, then right
		void pre_order (Node*);

		// prints out in order:  Left, self, then right
		void in_order(Node*);

		// prints out in post order:  left, right, then self
		void post_order(Node*);



	};
}
