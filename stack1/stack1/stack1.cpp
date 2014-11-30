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
#include <stack>
//#include "MyStack.h" // provides mystack class

using namespace std;


int main()

{
	ifstream input; // Will be attached to the input file
	char expression;
	

	
	stack<char> operators;

	input.open("tests.txt");
	if (input.fail( )) 
	{
		cerr << "Could not open input file." << endl;
	    exit(0); 
	}
	else
		input >> expression; // Read an integer from the input file

	

	
	while(input && input.peek( ) != EOF)
	{
		if(expression == '(')
		{
			operators.push(expression);
		}
		if(expression == '+' || expression == '-' || expression == '*' || expression == '/')
		{
			operators.push(expression);
		}
		if(isdigit(expression))
		{
			cout<<expression << " ";
		}

		if(expression == ')')
		{
			while(operators.top() != '(')
			{
				cout<<operators.top() << " ";
				operators.pop();
			}
			operators.pop();
		}


	}
	

	if((input && input.peek( ) == EOF))
	input.close( );	
	return 0;
}