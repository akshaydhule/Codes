//============================================================================
// Name        : binaryboundarynodes.cpp
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
	struct node * left, * right;
};

void leftnodes(struct node * root)
{
	if(root!=NULL)
	{
		cout <<root->data<<" ";
		if(root->left!=NULL)
		{
			leftnodes( root->left);
		}
		else if(root->right!=NULL)
		{
			leftnodes(root->right);
		}
	}
}
void rightnodes(struct node * root)
{
	if(root!=NULL)
	{
		if(root->right!=NULL)
			rightnodes(root->right);
		else if(root->left!=NULL)
			rightnodes(root->left);
		cout<<root->data<<" ";
	}
}

void leafnodes(struct node * root)
{
	if(root!=NULL)
	{
		leafnodes(root->left);
		if(root->left==NULL && root->right==NULL)
			cout<<root->data<<" ";
		leafnodes(root->right);
	}
}

void printboundary(struct node * root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		leftnodes(root->left);
		leafnodes(root->left);
		leafnodes(root->right);
		rightnodes(root->right);
	}
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
	struct node *root = newnode(11);
		root->left = newnode(2);
		    root->right = newnode(33);
		    root->left->left = newnode(6);
		    root->left->right = newnode(21);
		    root->right->left = newnode(3);
		    root->right->right = newnode(1);
		    printboundary(root);
	return 0;
}
