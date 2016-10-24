/*
//============================================================================
// Name        : Linkedlist_to_BST.cpp
// Description : Given a linked list convert it into
 * Binary Search tree
//============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Lnode
{
	int data;
	Lnode *next;
};

struct Tnode
{
	int data;
	Tnode *left, *right;
};

Lnode * Lnewnode(int val)
{
	struct Lnode *temp = new Lnode;
	temp->data = val;
	temp->next = NULL;
	return temp;
}

Tnode * Tnewnode(int val)
{
	Tnode *temp = new Tnode;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void buildlinkedlist(int a[], Lnode * root, int n)
{
	Lnode *temp1, *temp = root;
	for(int i=1;i<n;i++)
	{
		temp1 = Lnewnode(a[i]);
		temp->next = temp1;
		temp = temp->next;
	}
}

int size_ll(struct Lnode * root)
{
	Lnode * temp = root;
	int count=0;
	while(temp)
	{
		count ++;
		temp = temp->next;
	}
	return count;
}


Tnode * subtree(int l, int r, Lnode * root)
{
	int length = abs(r-l+1), count =0;
	int mid =l + length/2;
	Lnode *temp = root;
	while(count<mid)
	{
		count ++;
		temp = temp->next;
	}
	Tnode *Troot = Tnewnode(temp->data);
	if(l<mid)
		Troot->left = subtree(l, mid-1, root);
	if(mid<r)
		Troot->right = subtree(mid+1,r, root);
	return Troot;
}

Tnode * ll_to_tree(Lnode *root)
{
	Lnode *temp = root;
	int length = size_ll(root);
	Tnode * Troot;
	int l=0 ,r=length-1;
	int mid = (length%2)==1?(length+1)/2:length/2;
	int count = 0;
	while(count < mid)
	{
		count++;
		temp =temp->next;
	}
	Troot = Tnewnode(temp->data);
	if(0<mid)
		Troot->left = subtree(0,mid-1, root);
	if(mid<r)
		Troot->right = subtree(mid+1,r, root);
	return Troot;
}
void inorder(Tnode * root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

void printlist(Lnode * root)
{
	Lnode *temp  = root;
	while(temp)
	{
		cout<< temp->data;
		temp = temp->next;
	}
}

int main() {
	int a[] = {0,1,2,3,4,5,6,7,8};
	Lnode * root = Lnewnode(a[0]);
	int n = sizeof(a)/sizeof(a[0]);
	buildlinkedlist(a, root, n);
	printlist(root);
	Tnode * Troot = ll_to_tree(root);
	inorder(Troot);
	return 0;
}
