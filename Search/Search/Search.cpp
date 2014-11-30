// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: Search.cpp
// Date: 9/30/13

/*I Colton have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include "Search.h"

using namespace std;

Search::Search(int size, int seed)
{
	this->size = size;
    array = new int[size];
	set_seed(seed);
}

Search::~Search()
{
	delete [] array;
}


bool Search::sequential_find(int num)
{
	for(int i = 0; i < size; i++)
	{
		if(num == array[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

bool Search::recursive_binary_find(int num)
{
	int low = 0;
	int high = size-1;
	return recursive_binary_find(num,low,high);
}

bool Search::recursive_binary_find(int num, int low, int high)
{
	int half = 2;
	int mid = (low + high) / half;

	if(low > high)
	{
		return false;
	}
	
	
	if(array[mid] == num)
	{
		return true;
	}
	else if(num < array
		[mid])
	{
		return(num,low,mid-1);
	}
	else
	{
		return(num,mid+1,high);
	}
}

bool Search::iterative_binary_find(int num)
{
	int half = 2;
	int low = 0;
	int high = size -1;
	int mid = (low + high) / half;

	while(low <= high)
	{
		if( num == array[mid])
		{
			return true;
		}
		else if( num < array[mid])
		{
			high = mid-1;
			return false;
		}
		else
		{
			low = mid +1;
			return false;
		}
		
	}
}


void Search::init_array()
{
	srand(2);
	for(int i = 0; i < size; i++)
	{
		array[i] = rand();
	}

}

void Search::init_sorted_array()
{
	srand(2);
	for(int i = 0; i < size; i++)
	{
		if( i == 0)
		{
			array[i] = (rand() % size) +1;
		}
		else
		{
		array[i] = array[i-1] + (rand() % size) +1;
		}
	}
}

void Search::set_seed(int seed)
{
	srand(seed);
}

int Search::getSize()
{
	return size;
}