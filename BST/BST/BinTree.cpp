// Franklin Colton Parry
// Course: CS 2420 
// Instructor: Professor Peterson
// File: node.h
// Date: 10/28/13

/*I <name> have not used any code other than my own 
(or that in the textbook) for this project. I also 
have not used any function or data-structure from the 
Standard-Template Library. I understand that any 
violation of this disclaimer will result in a 0 for the project.
*/

#include <iomanip>
#include <iostream>
#include "bintree.h"
using namespace Node_1;
using namespace std;

bintree::bintree()
{
	root = NULL;
}


bintree::~bintree()
{
	
	remove_tree(root);
}

Node* bintree::getptr()
{
	return root;
}

void bintree::remove_tree(Node * r)
{
	if(r == NULL)
	{
		return;
	}
	else
	{
		remove_tree(r->left);
		remove_tree(r->right);
		delete r;
		root = NULL;
	}
}

int bintree::size(Node * n)
{ 
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + size(n->left) + size(n->right);
	}
}


void bintree::print(Node* n, int depth)
{
	cout <<::setw(4*depth) << ""; // indentation
	if(n == NULL)
	{
		cout << "[Empty]" << endl;
	}
	else if (n->left == NULL && n->right == NULL)
	{
		cout << n->data;
		cout << "[Leaf]" << endl;
	}
	else
	{
		cout << n->data << endl;
		print(n->left, depth+1);
		print(n->right, depth+1);
	}

}

void bintree::erase(Node *& n, int d)
{
	//base case if node = null, return
	if(n == NULL)
	{
		return;
	}
	

	// data is found
	if(n->data == d)
	{
		// if node is a leaf
		if(n->left == NULL && n-> right == NULL)
		{
			delete n;
			n = NULL;
			return;
		}

		//  if node has only one child
		if(n->left == NULL || n->right == NULL)
		{
			Node * temp = n;

			if(n->left == NULL)
			{
				n = n->right;
				delete temp;
			}
			else
			{
				n = n->left;
				delete temp;
			}

			temp = NULL;
		}
		
		// if node has two children
		/*find immediate predicessor, go left and then all the way right
		take ped up to data n
		delete the node and pull up children*/
		if(n->left != NULL && n->right != NULL)
		{
			Node *& ptr = n->left;
			
			while(ptr->right != NULL)
			{
				ptr = ptr->right;
			}

			n->data = ptr->data;
			Node * temp = ptr;
			ptr = ptr->left;
			delete temp;
			temp = NULL;


		}

	}



	// if data is not found
	if(n->data != d)
	{
		erase(n->left, d);
		erase(n->right, d);

		return;
	}

}


void  bintree::insert(Node *& n,int d)
{
	if(n == NULL)
	{
		n = new Node(d);
	}
	else if(n->data == d)
	{
		cout << "duplicate number" << endl;
		return;
	}
	else if(n->data > d)
	{
		insert(n->left,d);
	}
	else if(n->data < d)
	{
		insert(n->right,d);
	}
}

	
void bintree::pre_order(Node* n)
{
	if( n == NULL)
	{
		return;
	}
	else
	{
		cout << n->data << " ";
		pre_order(n->left);
		pre_order(n->right);
	}
}

void bintree::in_order(Node* n)
{

	if( n == NULL)
	{
		return;
	}
	else
	{
	    in_order(n->left);
		cout << n->data << " ";
		in_order(n->right);
	}
}

void bintree::post_order(Node* n)
{
	if( n == NULL)
	{
		return;
	}
	else
	{
		post_order(n->left);
		post_order(n->right);
		cout << n->data << " ";
	}
}