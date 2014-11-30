// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: node.cpp
// Date: 9/23/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include <cctype>   // provides isdigit
#include <cstdlib>  // provides EXIT_SUCCESS
#include <cstring>  // provides strchr
#include <iostream> // provides cout, cin, peek, ignore
#include <fstream>  // provides input stream

#include "MyStack.h" // provides stack class

using namespace std;
using namespace main_savitch_7A;


int main()

{
	ifstream input; // Will be attached to the input file
	char x;

	
	stack<char> characters;

	input.open("tests.txt");
	if (input.fail( )) 
	{
		cerr << "Could not open input file." << endl;
	    exit(0); 
	}


	do
	{
	
			if(input.peek() == '(')
			{
				input >> x;
				characters.push(x);			
			} else if (isdigit(input.peek()))
			{
				input >> x;
				characters.push(x);
			} else if (strchr("+-*/" , input.peek() != NULL))
			{
				while(characters.size() != 0 || characters.top() == '(')
				{
					cout << characters.top() << "";
					characters.pop();
				}

				input >> x;
				characters.push(x);
			} else 
			{
				input.ignore();
				if(characters.size() != 0)
				{
				cout << characters.top() << "";
				characters.pop();
				}
			}
		


	}while(input && input.peek( ) != EOF);
	
	input.close( );	
	
	system("PAUSE");
	
	return 0;
}