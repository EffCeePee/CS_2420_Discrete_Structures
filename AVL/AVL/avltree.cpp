
// Franklin Colton Parry
// Course: CS 2420
// Instructor:  Peterson
// File: avltree.cpp
// Date 11/12/13

/* I Colton Parry have not used any code other than my own
(or that in the text book) for this project.   I also 
have not used any function or datat-structure from the 
Standard-Template Library.  I understand that any
violation of this disclaimer will result in a 0 for the project.
*/
#include "avltree.h"

using namespace Node_1;
using namespace std;

avltree::avltree()
{
	root = NULL;
}

avltree::~avltree()
{
	remove_tree(root);
}

Node * avltree::getroot()
{
	return root;
}

void avltree::remove_tree(Node * r)
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

void avltree::print(Node * n, int depth)
{

	cout <<::setw(4*depth) << ""; // indentation
	if(n == NULL)
	{
		cout << "[Empty]" << endl;
	}
	else if (n->left == NULL && n->right == NULL)
	{
		cout << n->data;
		cout << "[Leaf]" /*<<  " " << "height is " << n->height */ <<endl;
	}
	else
	{
		cout << n->data/* << "height is " << n->height*/ << endl;
		print(n->left, depth+1);
		print(n->right, depth+1);
	}
}

void avltree::insert(Node * n, int d)
{
	if(n == NULL)
	{
		n = new Node(d);
		root = n;
	}
	else if(n->data == d)
	{
		cout << "duplicate number" << endl;
		return;
	}else if(n->data > d && n->left == NULL)
	{
		n->left = new Node(d);
		//n->adjust_height();
	}
	else if(n->data > d && n->left != NULL)
	{
		insert(n->left,d);
		//n->left = rebalance(n->left);
		
	} else if(n->right == NULL)
	{
		n->right = new Node(d);
		//n->adjust_height();
	} else if(n->right != NULL)
	{
		insert(n->right,d);
		// n->right = rebalance(n->right);
		
	}


	
}

Node* avltree::rotate_left(Node * oldRoot)
{
	Node * tempOldRoot = oldRoot;
	newRoot = oldRoot->right;
	Node * newRootleft = newRoot->left;

	newRoot->left = oldRoot;  
	tempOldRoot->right = newRootleft;

	return newRoot;
}

Node* avltree::rotate_right(Node * oldRoot)
{
	Node * tempOldRoot = oldRoot;
	newRoot = oldRoot->left;
	Node * newRootRight = newRoot->right;

	newRoot->right = oldRoot;  
	tempOldRoot->left = newRootRight;

	return newRoot;


	
}
void avltree::rebalance(Node* ptr)
{

}
