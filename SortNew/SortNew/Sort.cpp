// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: Sort.cpp
// Date:10/8/13

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
    myArray = new int[size];
}


void Sort::init_array(int size)
{
	srand(0);
	for(int i = 0; i < size; i++)
	{
		myArray[i] = rand() % size;
	}

}

Sort::~Sort()
{
	delete [] myArray;
}


void Sort::insertion_sort(int size)
{
		for(int index = 1; index < size; index++)
	{
		int i = index;
		int j = i-1;

		while(i > 0)
		{
			if(myArray[i] < myArray[j])
			{
				swap(myArray[i], myArray[j]);
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
        largest = myArray[0];
        index_of_largest = 0;
        for (j = 1; j <= i; ++j)
        {
            if (myArray[j] > largest)
            {
                largest = myArray[j];
                index_of_largest = j;
            }
        }
		swap(myArray[i], myArray[index_of_largest]);
    }
}

void Sort::swap( int &a, int &b)
{
	int t = -1;

	t = b;
	b = a;
	a = t;
}

// pg 646 and 650
void Sort::merge_sort(int myArray[], int size)
{
	
    int n1; // Size of the first subarray
    int n2; // Size of the second subarray

    if (size > 1)
    {
        // Compute sizes of the subarrays.
        n1 = size / 2;
        n2 = size - n1;

        merge_sort(myArray, n1);         // Sort from data[0] through data[n1-1]
        merge_sort((myArray + n1), n2);  // Sort from data[n1] to the end

        // Merge the two sorted halves.
        merge(myArray, n1, n2);
    }
	
}


	void Sort::merge(int myArray[], int n1, int n2)
	{
		{
    int *temp;       // Points to dynamic array to hold the sorted elements
    int copied  = 0; // Number of elements copied from data to temp
    int copied1 = 0; // Number copied from the first half of data
    int copied2 = 0; // Number copied from the second half of data
    int i;           // Array index to copy from temp back into data

    // Allocate memory for the temporary dynamic array.
    temp = new int[n1+n2];

    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2))
    {
        if (myArray[copied1] < (myArray + n1)[copied2])
            temp[copied++] = myArray[copied1++];        // Copy from first half
        else
            temp[copied++] = (myArray + n1)[copied2++]; // Copy from second half
    }

    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
        temp[copied++] = myArray[copied1++];
    while (copied2 < n2)
        temp[copied++] = (myArray+n1)[copied2++];

    // Copy from temp back to the data array, and release temp's memory.
    for (i = 0; i < n1+n2; i++)
        myArray[i] = temp[i];
    delete [ ] temp; 
}
	}

// pg 656  and 659 use pseudo code from book
void Sort::quick_sort(int myArray[], int size)
{
	
    int pivot_index;	// Array index for the pivot element
    int n1;					// Number of elements before the pivot element
    int n2;					// Number of elements after the pivot element

    if (size > 1)
    {
        // Partition the array, and set the pivot index.
        partition(myArray, size, pivot_index);

        // Compute the sizes of the subarrays.
        n1 = pivot_index;
        n2 = size - n1 - 1;
        
        // Recursive calls will now sort the subarrays.
        quick_sort(myArray, n1);
        quick_sort((myArray + pivot_index + 1), n2);
    
	}
}


void Sort::partition(int myArray[ ], int size, int& pivot_index)
{
	int pivot = myArray[0];
	int too_big_index = 1;			//index of first item after pivot
	int too_small_index = size-1;	// indes of last item

	

	while(too_big_index <= too_small_index)
	{
		
		while(too_big_index < size && myArray[too_big_index] <= pivot)
		{
			too_big_index++;
		}

		while(myArray[too_small_index] > pivot)
		{
			too_small_index--;
		}

		if(too_big_index < too_small_index)
		{
			
			swap(myArray[too_big_index],myArray[too_small_index]);
		}
	}
	
	pivot_index = too_small_index;
	myArray[0] = myArray[pivot_index];
	myArray[pivot_index] = pivot;
}





