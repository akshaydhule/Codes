//============================================================================
// Name        : isBST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

struct node
{
	int data;
	node * left, *right;
};

struct node* newNode(int data)
{
  struct node *node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int isBST(struct node * root, int min, int max)
{
	if (root== NULL)
	{
		return 1;
	}
	if( root->data<min || root->data>max)
	{
		return 0;
	}
	return isBST(root->left, min, root->data -1) && isBST(root->right, root->data +1, max);
}

int isBSTutil(node * root)
{
	return (isBST(root,INT_MIN, INT_MAX));
}

int main() {
	struct node *root = newNode(4);
	root->left        = newNode(2);
	root->right       = newNode(5);
	root->left->left  = newNode(1);
	root->left->right = newNode(3);

	if(isBSTutil(root))
		cout<<"is bst";
	return 0;
}
