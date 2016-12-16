//============================================================================
// Name        : BSTtoDLL.cpp
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
	struct node * left, *right;
};

struct node * binarytodll(struct node * root)
{
	if(root == NULL)
	{
		return root;
	}
	if(root->left!=NULL)
	{
		struct node * left = binarytodll(root->left);
		while(left->right!=NULL)
		{
			left=left->right;
		}
		left->right = root;
		root->left = left;
	}
	if(root->right!=NULL)
	{
		struct node * right = binarytodll(root->right);
		while(root->left!=NULL)
		{
			right = right->left;
		}
		right->left = root;
		root->right = right;
	}
	return root;
}

struct node * bsttodll(struct node * root)
{
	if(root==NULL)
	{
		return root;
	}
	struct node * head = binarytodll(root);
	while(head->left!=NULL)
		head = head->left;
	return head;
}

struct node * newnode(int data)
{
	struct node * root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return(root);
}
int main() {
	struct node *root = newnode(4);
	root->left = newnode(3);
	root->right = newnode(5);
	struct node * head = bsttodll(root);
	while(head!=NULL)
	{
		cout<<head->data;
		head=head->right;
	}
	return 0;
}
