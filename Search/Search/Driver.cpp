// Franklin Colton Parry
// Course:  CS 2420
// Instructor:  Professor Peterson
// File: Driver.cpp
// Date: 9/30/2013

/* I Colton have not used any code other than my own
(or that in the textbook) for theis project.  I also
have not used any frunction or data-structure form the 
Standard-Template Library.  I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include <fstream>
#include <iostream>
#include <ctime>
#include "search.h"

using namespace std;

const int loopSize = 1000000;

int main()
{
int arrSize = 10000;
int seeed = 5;
int number = rand();

Search myArray(arrSize, seeed);

myArray.init_array();


clock_t start1 = clock();
for(int i = 0; i < loopSize; i++)
{
	myArray.sequential_find(number);
}
clock_t end1 = clock();
clock_t diff1 = end1 - start1;
double seqTime = ((double)diff1 * CLOCKS_PER_SEC)/loopSize;


myArray.init_sorted_array();

clock_t start2 = clock();
for(int i = 0; i < loopSize; i++)
{
	myArray.recursive_binary_find(number);
}
clock_t end2 = clock();
clock_t diff2 = end2 - start2;
double recuTime = ((double)diff2 * CLOCKS_PER_SEC)/loopSize;



clock_t start3 = clock();
for(int i = 0; i < loopSize; i++)
{
	myArray.iterative_binary_find(number);
}
clock_t end3 = clock();
clock_t diff3 = end3 - start3;
double iterTime = ((double)diff3 * CLOCKS_PER_SEC)/loopSize;
cout << "" << endl;



cout << "\nfor an array of size " << myArray.getSize() << " one sequential search took "
	 << seqTime << " micro seconds" << endl;

cout << "for an array of size " <<  myArray.getSize() << " one iterative binary search took "
	 << iterTime << " micro seconds" << endl;

cout << "for an array of size " <<  myArray.getSize() << " one recursive binary search took "
	 << recuTime << " micro seconds" << endl;





system("PAUSE");
return 0;

}