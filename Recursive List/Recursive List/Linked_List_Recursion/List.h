#pragma once

#include <cstdlib>
#include "Node.h"

namespace list_2
{
	class List
	{
	
		Node *head;

		// helper function for the destructor
		// add other helper functions here to complete your program.
		// they should all contain one or more Node* as parameters
		void destroy(Node *n);
	public:
		// postcondition: list is initialized
		List();
		// postcondition: all nodes are destroyed using recursion
		~List();

		// postcondition: add element d at the end of the list
		//                using recursion
		void addEnd(int d);
		// postcondition: print the list ussing recursion
		void print();
		// precondition: list is in sorted order
		//                 (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains
		//                sorted order. using recursison.
		void insert(int d);

		// postcondition: if d is in the list then find returns true
		//                else find returns false
		bool find (int d);

		// postcondition: size is returned. Must be calculated using recursion.
		int size();

		// helper function for addEnd
		// postcondition:  add a node to the back of the list
		void addBack(Node*, Node*);
		
		// helper function for print
		// postcondition: print out the current node
		void printList(Node *);

		// helper function for insert
		// postcondition: see if new node data is less the current data
		//                if it is insert the new node
		void insertNode(Node *, Node *, Node *);

		// helper function for find
		// postcondition: see if data is in the list
		bool search(int, Node *);

		// helper function for size
		// postcondition: count the number of items in the list
		int count(Node *);


	};
}