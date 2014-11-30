
// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: Search.cpp
// Date: 10/7/13

/*I Colton have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

class Sort
{
public:

	// constructor
	Sort(int size);

	// destructor
	~Sort();


	void insertion_sort(int size);
	void selection_sort(int size); // pg 634 and swap();
	void merge_sort(int array[], int size); // pg 646 and 650
	//void quick_sort(); // pg 656 and write partition(); use psuedocode from book;
	void merge(int array[], int n1, int n2);
	void init_array(int size);


	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		// put the code in here.
		for(int i = 0; i < s.size; i++)
		{
			out << s.array[i] << " "; 
		}
		return out;
	}
	

	

private:

	int size;
	int* array;

	// all helper functions are private
	
	void swap(int , int);

	// called by quicksort();
	//void partition();


	


	
};
