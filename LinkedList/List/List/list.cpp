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
		
		nn->next = 0;
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
	
	if(head == 0)
	{
		return;
	}

	Node * temp1 = head;
	Node * temp2 = head;

	while(temp1 != 0)
	{
		if(head->data == entry)
		{
			temp1 = head->next;
			delete head;
			head = temp1;
		}
		else
		{
			temp1 = temp1->next;
			if(temp1 != 0)
			{

				if(temp1->data == entry)
				{
					temp1 = temp1->next;
					delete temp2->next;
					temp2->next = temp1;
				}
				else
				{
					temp1 = temp1->next;
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

