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

class Lnode
{
public:
	int data;
	Lnode * prev, *next;
	Lnode(int data): data(data), prev(NULL), next(NULL){}
};

Lnode * bst_to_dll(struct node * root)
{
	if (root->left==NULL && root->right == NULL)
	{
		struct Lnode * curr = new Lnode(root->data);
		return curr;
	}
	Lnode * head = bst_to_dll(root->left);
	Lnode * curr = new Lnode(root->data);
	head->next = curr;
	curr->prev = head;
	Lnode *next = bst_to_dll(root->right);
	curr->next = next;
	next->prev = curr;
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
	Lnode * head = bst_to_dll(root);
	while(head!=NULL)
	{
		cout<<head->data;
		head=head->next;
	}
	return 0;
}
