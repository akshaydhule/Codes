//============================================================================
// Name        : LCAofBST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left, * right;
};

struct node * newnode(int data)
{
	struct node *root = new node;
	root->data = data;
	root->left = root->right = NULL;
	return (root);
}
//recursive function
struct node *lca(struct node *root, int a, int b)
{
	if(root==NULL)
	{
		return root;
	}
	if(root->data>a && root->data>b)
	{
		root = lca(root->left, a, b);
	}
	if(root->data<a && root->data<b)
	{
		root = lca(root->right, a, b);
	}
	return root;
}

//iterative function
struct node *itlca(struct node *root, int a, int b)
{
	if(root==NULL)
	{
		return root;
	}
	while(root!=NULL)
	{
	if(root->data>a && root->data>b)
	{
		root = root->left;
	}
	if(root->data<a && root->data<b)
	{
		root = root->right;
	}
		break;
	}
	return root;
}


int main() {
	struct node *root = newnode(10);
	root->left = newnode(6);
	root->right = newnode(14);
	root->left->left = newnode(3);
	root->left->right = newnode(7);
	root->right->right = newnode(17);
	root->right->left = newnode(11);
	struct node *ancestor = itlca (root, 7,11);
	cout<<ancestor->data;
	return 0;
}
