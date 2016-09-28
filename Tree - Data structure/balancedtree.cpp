//============================================================================
// Name        : balancedtree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include<algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct node
{
	int data;
	struct node * left, *right;
};

struct node * newnode(int data)
{
	struct node * root = (struct node *)malloc(sizeof(node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return(root);
}

int height(struct node *root)
{
	if(root==NULL)
		return 0;
	return(1+max(height(root->left),height(root->right)));
}

bool balanced(struct node * root)
{
	if(root==NULL)
	{
		return true;
	}
	else
	{
		int l = height(root->left);
		int r = height(root->right);
		if(abs(l-r)<=1)
		{
			if(balanced(root->left)==true && balanced(root->right)==true)
				return true;
		}
	}
	return false;
}

int balancedt(struct node * root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int l = balancedt(root->left)+1;
		int r = balancedt(root->right)+1;
		if(abs(l-r)<=1)
		{
			return max(l,r);
		}
		else
			return INT_MAX;
	}
}

bool bst(struct node * root)
{
	if(root==NULL)
		return true;
	else
	{
		if(root->left!=NULL)
		{	bst(root->left);
			if(root->left->data>root->data)
				return false;
		}
		if(root->right!=NULL)
		{	bst(root->right);
			if(root->data>root->right->data)
				return false;
		}
	}
	return true;
}

int main() {
	struct node *root = newnode(11);
	root->left = newnode(21);
		    root->right = newnode(33);
		    root->left->left = newnode(6);
		    root->left->right = newnode(21);
		    root->right->left = newnode(3);
		    root->right->right = newnode(1);
		    root->right->right->right = newnode(1);
		    root->right->right->right->right = newnode(12);
	//cout<<balanced(root);
	if(balancedt(root)!=INT_MAX)
		cout<<"its balanced";
	else
		cout<<"its not";
	cout<<bst(root);
	return 0;
}
