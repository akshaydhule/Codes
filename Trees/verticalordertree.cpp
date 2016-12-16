//============================================================================
// Name        : verticalordertree.cpp
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

void findminmax(struct node * root, int *min,int *max,int dist)
{
	if(root==NULL)
	{
		return;
	}
	if(dist<(*min))
		*min =dist;
	if(dist>(*max))
		*max = dist;

	findminmax(root->left, min, max, dist-1);
	findminmax(root->right, min, max, dist+1);
}

void printverticalline(struct node * root,int order, int dist)
{
	if(root==NULL)
	{
		return;
	}

	if(order==dist)
	{
		cout<<root->data << " ";
	}

		printverticalline(root->left,order,dist-1);
		printverticalline(root->right,order,dist+1);
}

void printvertical(struct node *root)
{
	int min =0;
	int max =0;
	findminmax(root,&min,&max,0);
	for(int order = min;order<=max;order++)
	{
		printverticalline(root, order, 0);
		cout<<"\n";
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
	printvertical(root);
	return 0;
}
