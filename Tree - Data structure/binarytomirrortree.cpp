//============================================================================
// Name        : binarytomirrortree.cpp
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

void mirror(struct node * root)
{
	if(root==NULL)
		return;
	else{
	mirror(root->left);
	mirror(root->right);
	struct node * temp = new node;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	}
}
void itmirror(struct node * root)
{
	if (root==NULL)
		return;
	struct node * left = root->left;
			struct node * right = root->right;
	while(root!=NULL)
	{
		struct node * temp = new node;
		temp = left;
		left = right;
		right = temp;
		left = left->left;
		right = right->right;
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

void inorder(struct node * root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{	inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main() {
	struct node *root = newnode(11);
	root->left = newnode(2);
	    root->right = newnode(33);
	    root->left->left = newnode(6);
	    root->left->right = newnode(21);
	    root->right->left = newnode(3);
	    root->right->right = newnode(1);
	    inorder(root);
	    cout<<"\n";
	mirror(root);
	inorder(root);
	return 0;
}
