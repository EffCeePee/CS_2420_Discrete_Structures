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

#include "Sort.h"

using namespace std;


Sort::Sort(int size)
{
	this->size = size;
    	array = new int[size];
}

Sort::~Sort()
{
	delete [] array;
}


void Sort::insertion_sort(int size)
{
		for(int index = 1; index < size; index++)
	{
		int i = index;
		int j = i-1;

		while(i > 0)
		{
			if(array[i] < array[j])
			{
				swap(i, j);
				i--;
				j--;
			}		
			else
			{
				i--;
				j--;
			}
		}
	}


}


// pg 634
void Sort::selection_sort(int size)
{
    int i, j, index_of_largest;
    int largest;

    if (size == 0)
        return; // No work for an empty array.
        
    for (i = size-1; i > 0; --i)
    {
        largest = array[0];
        index_of_largest = 0;
        for (j = 1; j <= i; ++j)
        {
            if (array[j] > largest)
            {
                largest = array[j];
                index_of_largest = j;
            }
        }
        swap(i, index_of_largest);
    }
}

void Sort::swap( int a, int b)
{
	int  t = -1;

	t = array[b];
	array[b] = array[a];
	array[a] = t;
}

// pg 646 and 650
void Sort::merge_sort(int array[], int size)
{
	{
    int n1; // Size of the first subarray
    int n2; // Size of the second subarray

    if (size > 1)
    {
        // Compute sizes of the subarrays.
        n1 = size / 2;
        n2 = size - n1;

        merge_sort(array, n1);         // Sort from data[0] through data[n1-1]
        merge_sort((array + n1), n2);  // Sort from data[n1] to the end

        // Merge the two sorted halves.
        merge(array, n1, n2);
    }
	}
}


	void Sort::merge(int array[], int n1, int n2)
	{
		{
    int *temp;          // Points to dynamic array to hold the sorted elements
    int copied  = 0; // Number of elements copied from data to temp
    int copied1 = 0; // Number copied from the first half of data
    int copied2 = 0; // Number copied from the second half of data
    int i;           // Array index to copy from temp back into data

    // Allocate memory for the temporary dynamic array.
    temp = new int[n1+n2];

    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2))
    {
        if (array[copied1] < (array + n1)[copied2])
            temp[copied++] = array[copied1++];        // Copy from first half
        else
            temp[copied++] = (array + n1)[copied2++]; // Copy from second half
    }

    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
        temp[copied++] = array[copied1++];
    while (copied2 < n2)
        temp[copied++] = (array+n1)[copied2++];

    // Copy from temp back to the data array, and release temp's memory.
    for (i = 0; i < n1+n2; i++)
        array[i] = temp[i];
    delete [ ] temp; 
}
	}

// pg 656  use pseudo code from book
//void Sort::quick_sort()
//{
//
//}


//void Sort::partition()
//{
//
//}

void Sort::init_array(int size)
{
	srand(0);
	for(int i = 0; i < size; i++)
	{
		array[i] = rand() % size;
	}

}



