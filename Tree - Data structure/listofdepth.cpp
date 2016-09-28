//============================================================================
// Name        : listofdepth.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

struct node
{
	int data;
	struct node * left, *right;
};

struct node* newnode(int d)
{
	struct node *root;
	root->data = d;
	root->left = root->right = NULL;
	return root;
}
/*
void depthlist(struct node * root,list<node *> current, int depth, int level)
{
	if(root==NULL)
		return NULL;
	if(depth == level)
	{
		current.push_back(root);
	}

	if(root->left!=NULL)
		depthlist(root->left, current, depth,level+1);
	if(root->right!=NULL)
		depthlist(root->right,current, depth,level+1);
}
*/

int getdepth(struct node * root)
{
	if(root==NULL)
		return 0;
	else
	{
		return (1+max(getdepth(root->left),getdepth(root->right)));
	}
}

list<list<node *> > buildlist(struct node * root)
{
	list<node *> current, parent;
	list<list<node *> > final;
	if(root!=NULL)
	{
		current.push_back(root);
	}
	while(current.size()>0)
	{
		final.push_back(current);
		parent = current;
		current.clear();
		list<node*>::iterator it;
		it = parent.begin();
		while(it!=parent.end())
		{
			if((*it)->left!=NULL)
				current.push_back((*it)->left);
			if((*it)->right!=NULL)
				current.push_back((*it)->right);
			it++;
		}
	}
	return final;
}
int main() {
	node *root = newnode(4);
	root->left = newnode(2);
	root->right = newnode(6);
	root->left->left = newnode(1);
	root->left->right = newnode(3);
	list<list<node *> > output = buildlist(root);
	list<node*>:: iterator it2;
	list<list<node *> >::iterator it1;
	for(it1=output.begin();it1!=output.end();it1++)
	{
		for(it2=(*it1).begin();it2!=(*it1).end();it2++)
		{
			cout<<(*it2)->data<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
