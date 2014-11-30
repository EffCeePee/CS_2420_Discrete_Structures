// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: list.cpp
// Date: 9/10/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/


#include "list.h"


using namespace list_1;

list::list()
{
	head = 0;
	
}


list::~list(void)
{
		while(head != 0)
	{
		if(head->next == 0)
		{
			delete head;
			head = 0;
		}
		else if(head->next != 0)
		{
		
			Node * temp = head->next;
			delete head;
			head = temp;
			return;
		}
	}
}

void list::insert_front(const int& entry)
{
	Node * nn = new Node(entry);

	if(head == 0)
	{
		head = nn;
		return;
	}
	
	if(head != 0)
	{
		
		nn->next = head;
		head = nn;
		return;
	}
}


void list::add_back(const int& entry)
{
	Node * nn = new Node(entry);

	if(head == 0)
	{
		head = nn;
		return;
	}

	if(head != 0)
	{
		
		Node * temp = head;

		while(temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = nn;
		return;	
	}
}


void list::remove_all(const int& entry)
{
	// first condition no data
	if(head == 0)
	{
		return;
	}

	Node * temp1 = head;
	Node * temp2 = head;
	
	while(temp1 != 0)
	{
		// second condition the head is to be removed
		if(head->data == entry)
		{
			temp1 = head->next;
			delete head;
			head = temp1;
			temp2 = head;
		}

		// third condition is there is data in the list
		else
		{
			temp1 = temp1->next;
			if(temp1 != 0)
			{

				if(temp1->data == entry)
				{
					// fourth condition end of the list
					if(temp1->next == 0)
					{
						delete temp1;
						temp2->next = 0;
						temp1 = 0;
					}

					// fifth condition middle of the list
					else
					{
						temp1 = temp1->next;
						delete temp2->next;
						temp2->next = temp1;
						temp2 = temp1;
					}
				}
				else
				{
					temp2 = temp2->next;
				}
			}
		}
	}


}



int list::size() const
{
	int size = 0;
	
	if(head == 0)
	{
		return size;
	}
	else
	{
	Node * temp = head;

	while(temp != 0)
		{
			temp = temp->next;
			size++;
		}
	}

	return size;
}

Iterator list::begin(void)
{
	Iterator i(head);
		
	return i;
}