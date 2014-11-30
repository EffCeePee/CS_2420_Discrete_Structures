// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: list.cpp
// Date: 9/16/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "List.h"		// With value_type defined as an int

using namespace std;
using namespace list_2;

List::List()
{
	head= NULL;
}

List::~List()
{
	Node * n = head;
	destroy(n);	

}

void List::destroy(Node * n)
{
	if(n->next != NULL)
	{
		Node * nn = n->next;
		delete n;
		n = nn;
		destroy(n);
	}
	else
	{
		delete n;
	}
	

}


void List::addEnd(int d)
{

	Node * temp1 = new Node(d);
	Node * temp2 = head;
	addBack(temp1, temp2);


}

void List::addBack(Node * temp1, Node * temp2)
{
	if(head == NULL)
	{
		head = temp1;
	}
	else if(temp2->next == NULL)
	{
		temp2->next = temp1;
	}
	else
	{
		addBack(temp1, temp2->next);
	}	


}


void List::print()
{
   Node * temp = head;

	printList(temp);

}

void List::printList(Node * temp)
{
	if(temp != NULL)
	{
		cout << temp->data << endl;
		printList(temp->next);
	}
}


void List::insert(int d)
{

	Node * nn = new Node(d);
	Node * leader = head;
	Node * trailor = head;
	insertNode(nn, leader, trailor);		

}


void List::insertNode(Node * nn,Node * leader, Node * trailor)
{
	
	if(head == NULL)
	{
		head = nn;
	}
	else if(head->data > nn->data)
	{
		nn->next = head;
		head = nn;
	}
	else if(head->next == NULL)
	{
		head->next = nn;
	}
	else if(leader->data > nn->data)
	{
		nn->next = leader;
		trailor->next = nn;
	}
	else if(leader->next != NULL)
	{
		trailor = leader;
		leader = leader->next;
		insertNode(nn, leader, trailor);
	}	
	else
	{
		leader -> next = nn;
	}
	

}




bool List::find (int d)
{

	Node* temp = head;
	return search(d, temp);
}


bool List::search(int d, Node * temp)
{
	
	if(temp == NULL)
	{
		return false;
	}
	else if(temp->data == d)
	{
		return true;
	}
	else
	{	
		temp = temp ->next;
		return search(d, temp);
	}

}



int List::size()
{
	Node * temp = head;
	return count(temp);

}

int List::count(Node * temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		temp = temp->next;
		return 1 + count(temp);
	}
}