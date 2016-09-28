//============================================================================
// Name        : buildbinarytree.cpp
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
	struct node * left, *right;
};

struct node * setvalue(int midval)
{
	struct node *root = (struct node *) malloc(sizeof(struct node));
	root->data = midval;
	root->left =root->right = NULL;
	return root;
}
/*
struct node * tree(int a[],int l, int h)
{
	if(l>h)
	{
		return NULL;
	}
		int mid = (h-l)/2+l;
		struct node *root = setvalue(a[mid]);
		root->left = tree(a,l,mid-1);
		root->right = tree(a,mid+1,h);
		return root;
}

*/

struct node * tree(int a[],int l, int h)
{
	while(l<=h)
	{	int mid = (h-l)/2+l;
		struct node *root = setvalue(a[mid]);
		root->left = tree(a,l,mid-1);
		root->right = tree(a,mid+1,h);
		return root;
	}
	return NULL;
}

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	cout<<root->data;
	inorder(root->left);
	inorder(root->right);
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a)/sizeof(a[0]);
	struct node *root = tree(a,0,n-1);
	inorder(root);
	return 0;
}
