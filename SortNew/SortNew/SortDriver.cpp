// Franklin Colton Parry
// Course:  CS 2420
// Instructor:  Professor Peterson
// File: Driver.cpp
// Date: 10/7/2013

/* I Colton have not used any code other than my own
(or that in the textbook) for theis project.  I also
have not used any frunction or data-structure form the 
Standard-Template Library.  I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include <fstream>
#include <iostream>
#include <ctime>
#include "Sort.h"

using namespace std;

const int loopSize = 10000;

int main()
{
int arrSize = 30;

// intialzie the object and populate it
Sort sortObj(arrSize);
sortObj.init_array(arrSize);


//******************************insertion sort**********************

clock_t start1 = clock();
for(int i = 0; i < loopSize; i++)
{
	sortObj.init_array(arrSize);
	sortObj.insertion_sort(arrSize);
}
clock_t end1 = clock();
clock_t diff1 = end1 - start1;
double insertionSortTime = (double)diff1*CLOCKS_PER_SEC  / loopSize;

cout << "\nfor an array of size " << arrSize << " one insertion sort  took "
	 << insertionSortTime << " micro seconds" << endl;



//*******************************Selection Sort*********************

clock_t start2 = clock();
for(int i = 0; i < loopSize; i++)
{
	sortObj.init_array(arrSize);
	sortObj.selection_sort(arrSize);
}
clock_t end2 = clock();
clock_t diff2 = end2 - start2;
double selectSortTime = (double)diff2*CLOCKS_PER_SEC  /loopSize;

cout << "for an array of size " <<  arrSize << " one selection sort took "
	 << selectSortTime << " micro seconds" << endl;


//******************************MERGE SORT*************************


clock_t mergeStart = clock();
for(int i = 0; i < loopSize; i++)
{
	sortObj.init_array(arrSize);
	sortObj.merge_sort(sortObj.myArray, arrSize);
}
clock_t mergeEnd = clock();
clock_t mergeTime = mergeEnd - mergeStart;

double mergeSortTime = (double)mergeTime*CLOCKS_PER_SEC  /loopSize;

cout << "for an array of size " << arrSize << " one merge sort took "
	 << mergeSortTime << " micro seconds" << endl;



//**************************quick sort********************************

clock_t quickStart = clock();
for(int i = 0; i < loopSize; i++)
{
	sortObj.init_array(arrSize);
	sortObj.quick_sort(sortObj.myArray, arrSize);
}
clock_t quickEnd = clock();
clock_t quickDifference = quickEnd - quickStart;

double quickSortTime = (double)quickDifference*CLOCKS_PER_SEC  /loopSize;

cout << "for an array of size " << arrSize << " one quick sort took "
	 << quickSortTime << " micro seconds" << endl;


//************************end sorts**************************************
cout << "" <<  endl;


system("PAUSE");
return 0;

}