//============================================================================
// Name        : BST-InsertDelete.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left, *right;
	node(int d)
	{
		data = d;
		left = right = NULL;
	}
};


//delete and insert
void deleteNodeBST(node *root, node *curr)
{
	node *head = root;
	node  *parent = NULL;
	while(head->data != curr->data && head!=NULL)
	{
		parent = head;
		head = head->data > curr->data ? head->left : head->right;
	}
	node *current = head;
	if(current->right!=NULL)
	{
		node * rcurr = current->right;
		node * rparent = current;
		//leftmost node of right subtree
		while(rcurr->left!=NULL)
		{
			rparent = rcurr;
			rcurr = rcurr->left;
		}
		//update node
		current->data = rcurr->data;
		//pass on right child to rparent left
		if(rparent->left == rcurr)
			rparent->left = rcurr->right;
		else //no left child so move up the right child
			rparent->right = rcurr->right;
		rcurr->right = NULL;
	}
	else{
		//if its root node
		if(current == root)
		{
			root = current->left;
			current->left = NULL;
		}
		//if its left node
		else if(parent->left == current)
		{
			parent->left = current->left;
		}
		else{
			parent->right = current->left;
		}
		current->left = NULL;
	}
}

void insertNodeBST(node *root, node *curr)
{
	if(root == NULL)
		root = curr;
	else
	{
		node *current = root;
		node *parent = root;
		while(current != NULL)
		{
			parent = current;
			if(current->data < curr->data)
				current = current->left;
			else
				current = current->right;
		}
		if(parent->data > curr->data)
			parent->left = curr;
		else
			parent->right = curr;
	}
}

void printBST(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<endl;
	if(root->left != NULL)
	{
		cout<<"left subtree";
		printBST(root->left);
		cout<<endl;
	}
	if(root->right != NULL)
	{
		cout<<"right subtree";
		printBST(root->right);
		cout<<endl;
	}
}

int main() {
	node *root = new node (1);
	insertNodeBST(root, new node(2));
	insertNodeBST(root, new node(3));
	insertNodeBST(root, new node(4));
	insertNodeBST(root, new node(5));
	printBST(root);
	deleteNodeBST(root, new node(3));
	printBST(root);
	return 0;
}
