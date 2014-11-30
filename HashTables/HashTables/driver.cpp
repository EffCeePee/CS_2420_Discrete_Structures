// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: driver.cpp
// Date: 11/26/2013

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/



#include "hashtable.h"


using namespace hash_table;


#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <fstream>

// parser function
double parser(string, hashtable);

int main( )
{
	ifstream input;
	ifstream formula;
	string name = "nothing";
	string fname = "fname";

	int fweight = 0;
	double weight = 0.00;
	int findex;
	int capacity = 193;

	hashtable element;

	//element.insert("SO", 9999);
	//element.insert("SO", 1111);
	//element.retrieve("SO");

	input.open("PeriodicTable.txt");

	cout << "The periodic table will be read in" << endl;


	if(input.fail())
	{
		cerr << "Could not open input file." << endl;
	    exit(0); 
	}

		while(input.peek() != EOF)
		{
			if (isalpha(input.peek()))
			{
				input >> name;
			}
			else if(isdigit(input.peek()))
			{
			input >> weight;
			}
			else if(input.peek() == ' ')
			{
			input.ignore();
			}
			else if(input.peek() == '\n')
			{
				element.insert(name,weight);
				input.ignore();
			}

		} 
	input.close();
	cout << "lets calculate some molecular weights" << endl;

	formula.open("formulas.txt");

	if(formula.fail())
	{
		cerr << "Could not open input file." << endl;
	    exit(0); 
	}


	while(formula.peek() != EOF)
	{
		getline(formula,fname);
		
		fweight = parser(fname, element);
		
		cout << "the formula is " << fname << " and the weight is " << fweight << endl;
	}

	formula.close();

	system("PAUSE");
	return EXIT_SUCCESS;
}


double parser(string fname, hashtable element)
{
	string elName;
	double formWeight = 0;
	for(int i = 0; i < fname.length(); i++)
	{
		if(isalpha(fname[i]))
		{
			elName = elName + fname[i];
		}
		else if(isdigit(fname[i]))
		{
			formWeight = element.retrieve(elName);
			formWeight *= fname[i];
			elName = "";

		}
		else if(fname[i] == '\n')
		{
			return formWeight;
		}
	}
}