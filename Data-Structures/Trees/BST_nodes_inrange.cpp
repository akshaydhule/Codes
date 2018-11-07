/*
//============================================================================
// Name        : BST_nodes_inrange.cpp
// Description : Given a binary search tree,
 * Augment it to return number of nodes in given range
//============================================================================
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class node
{
public:
	int data;
	node * left, * right;
	int lcount, rcount;
	node(int a): data(a), left(NULL), right(NULL), lcount(0), rcount(0){}
};

//1. 1st method
int augment(node * root)
{
	if(!root)
		return 0;
	else
	{
		if(root->left)
			root->lcount = 1 + augment(root->left);
		if(root->right)
			root->rcount = 1 + augment(root->right);
		return root->lcount + root->rcount;
	}
}

int lcount(node * root, int l)
{
	if(l == root->data)
		return 1+ root->rcount;
	if(l<root->data)
		return root->rcount + lcount(root->left, l);
	if(l>root->data)
		return lcount(root->right, l);
	return 0;
}

int rcount(node * root, int r)
{
	if(r == root->data)
		return 1 + root->lcount;
	if(r<root->data)
		return rcount(root->left, r);
	if(r>root->data)
		return root->lcount + rcount(root->right, r);
	return 0;
}



int inrange_nodes(node * root, int l, int r)
{
	if(l<root->data && r < root->data)
		return inrange_nodes(root->left, l, r);
	if(l>root->data && r > root->data)
		return inrange_nodes(root->right, l, r);
	if(l<root->data && r > root->data)
	{
		return 1 + lcount(root->left, l) + rcount(root->right,r);
	}
	return 0;
}
// 2. 2nd Method
string inorder(node *root)
{
	if(root->left == NULL && root->right == NULL)
		return to_string(root->data);
	string left = inorder(root->left);
	string s = std::to_string(root->data);
	string right = inorder(root->right);
	return left + s +  right;
}
int inrange_count(node * root, int l, int r)
{
	string value = inorder(root);
	int i=0;
	for( i=0;i<value.size();i++)
	{
		if ((value[i] - '0') == l)
			break;
	}
	int count = 1;
	while(i< value.size() && (value[i]-'0') != r)
	{
		count++;
		i++;
	}
	return count;
}

int main() {
	node * root = new node(4);
	node * l = new node(2);
	node * r = new node(6);
	node * ll = new node(1);
	node * lr = new node(3);
	node * rr = new node(7);
	node * rl = new node(5);
	root->left = l;
	root->right = r;
	root->left->left = ll;
	root->left->right = lr;
	root->right->left = rl;
	root->right->right = rr;
	//cout<<augment(root);
	//cout<<inrange_nodes(root, 5,7);
	cout<<inrange_count(root, 5,7);
	return 0;
}
