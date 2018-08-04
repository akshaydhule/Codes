//============================================================================
// Name        : Tree-CartesianTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
	int data;
	node * left, *right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node * BuildTree(int root, int array[], int parent[], int leftChild[], int rightChild[])
{
	if (root == -1)
		return NULL;

	node *temp = new node(array[root]);
	temp->left = BuildTree(leftChild[root], array, parent, leftChild, rightChild);
	temp->right = BuildTree(rightChild[root], array, parent, leftChild, rightChild);
	return temp;
}

node * MaxTree(int array[], int n)
{
	int parent[n], leftChild[n], rightChild[n];
	memset(parent, -1, sizeof(parent));
	memset(leftChild, -1, sizeof(leftChild));
	memset(rightChild, -1, sizeof(rightChild));

	int root = 0, last;
	for(int i = 1; i < n; i++)
	{
		last = i-1;
		rightChild[i] = -1;

		while(array[last] <= array[i] && last!=root)
			last = parent[last];

		//new is largest
		if(array[last] <= array[i])
		{
			parent[root] = i;
			leftChild[i] = root;
			root = i;
		}
		//largest already in tree
		else
		{
			parent[rightChild[last]] = i;
			leftChild[i] = rightChild[last];
			rightChild[last] = i;
			parent[i] = last;
		}
	}

	parent[root] = -1;
	return BuildTree(root, array, parent, leftChild, rightChild);
}

node * MinTree(int array[], int n)
{
	int parent[n], leftChild[n], rightChild[n];
	memset(parent, -1, sizeof(parent));
	memset(leftChild, -1, sizeof(leftChild));
	memset(rightChild, -1, sizeof(rightChild));

	int root = 0, last;
	for(int i = 1; i < n; i++)
	{
		last = i-1;
		rightChild[i] = -1;

		//find smallest value
		while(array[last] > array[i] && last!=root)
			last = parent[last];

		//new is smallest
		if(array[last] > array[i])
		{
			parent[root] = i;
			leftChild[i] = root;
			root = i;
		}
		//smallest already in tree
		else
		{
			parent[rightChild[last]] = i;
			leftChild[i] = rightChild[last];
			rightChild[last] = i;
			parent[i] = last;
		}
	}

	parent[root] = -1;
	return BuildTree(root, array, parent, leftChild, rightChild);
}

void inorder(node * root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int main() {
	int a[] = {5, 10, 40, 30, 28};
	int n = sizeof(a)/sizeof(a[0]);
	node* tree = MinTree(a, n);
	inorder(tree);
	return 0;
}
