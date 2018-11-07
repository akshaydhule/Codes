//============================================================================
// Name        : BT-BSTorNot.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

class node
{
public :
	int data;
	node* left, *right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

bool BSTUtil(node* root, int min, int max)
{
	if(root == NULL)
		return true;
	if(root->data<min || root->data > max)
		return false;
	return ( BSTUtil(root->left, min, root->data) && BSTUtil(root->right, root->data, max));
}

bool BST(node* root)
{
	return BSTUtil(root, INT_MIN, INT_MAX);
}


int main() {
	node* root = new node(3);
	root->left = new node(2);
	root->left->left = new node(1);
	root->left->right = new node(4);
	root->right = new node(4);
	cout<<BST(root);
	return 0;
}
