//============================================================================
// Name        : tree_traversals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;


struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode(int data)
{
	struct node * node = (struct node *) malloc (sizeof(struct node));
	node -> data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
};

void preorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->data;
	preorder(node->left);
	preorder(node->right);
}
void inorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}

	preorder(node->left);
	cout<<node->data;
	preorder(node->right);

}

void postorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}

	preorder(node->left);
	preorder(node->right);
	cout<<node->data;

}

int sizeoftree(struct node * root)
{
	if(root==NULL)
		return 0 ;
	else
		return (sizeoftree(root->left)+1+sizeoftree(root->right));
}

int main() {
	struct node *root;
	root = newnode(5);
	root->left = newnode(3);
	root->right = newnode(7);
	root->left->left = newnode(2);
	root->left->right = newnode(4);
	root->right->left = newnode(6);
	cout<<"\npreorder:";
	preorder(root);
	cout<<"\npostorder:";
	postorder(root);
	cout<<"\ninorder:";
	inorder(root);
	cout<<"\nsizeoftree:"<<sizeoftree(root);
	return 0;
}
