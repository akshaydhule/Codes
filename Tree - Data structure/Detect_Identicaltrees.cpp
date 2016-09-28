//============================================================================
// Name        : Detect_Identicaltrees.cpp
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

int identicaltrees(struct node * root1, struct node * root2)
{
	if(root1==NULL && root2==NULL)
	{
		return 1;
	}
	else if (root1!=NULL && root2!=NULL)
	{
		return(root1->data == root2->data &&
			identicaltrees(root1->left,root2->left) &&
			identicaltrees(root1->right,root2->right));
	}
	return 0;
}

int main() {
	struct node *root1;
	root1 = newnode(5);
	root1->left = newnode(3);
	root1->right = newnode(7);
	root1->left->left = newnode(2);
	root1->left->right = newnode(4);
	root1->right->left = newnode(6);

	struct node *root2 = newnode(5);
	root2->left = newnode(3);
	root2->right = newnode(7);
	root2->left->left = newnode(2);
	root2->left->right = newnode(4);
	root2->right->left = newnode(6);

	if(identicaltrees(root1, root2)==1)
	{
		cout<<"they are identical";
	}
	else
		cout<<"they are not";

	return 0;
}
