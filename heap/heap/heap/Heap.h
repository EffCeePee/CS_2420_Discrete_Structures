// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: Heap.H
// Date 11/4/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/

#pragma once

#ifndef Heap_H
#define Heap_H
#include <iostream>
#include <iomanip>

namespace heap_1
{
	class heap
	{
	private:
		// member constants
		static const int two = 2;
		int index;
		int * heapArray;
		int used;
		static const int size = 10;

	public:

		// constructor
		heap();

		// destructor
		~heap();

		// places an element at the end of the heap
		// then bubbles up to place it in the correct postion
		void insert(int);

		// switches the element to the last element in the heap
		// then bubbles down to put the element in the correct postion
		// returns the last element 
		int remove_front();

		/// prints out the heap on a single line
		void print();

		// prints out the tree in tabbed format
		void print_tree(int,int);

		// swaps the two integers in the heap array
		void swap(int&, int&);

		int get_size();


	};
}
#endif



