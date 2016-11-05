/*
//============================================================================
// Name        : root_to_leaf_paths.cpp
// Description : Print all routes from root to leaf
//============================================================================
*/
#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
	int data;
	node * left, * right;
	node (int d): data(d), left(NULL), right(NULL)
	{}

};

void print_stack(stack<node *> path)
{
	node * top;
	if(path.empty())
		return;
	else
	{
		top = path.top();
		path.pop();
		print_stack(path);
		cout<<top->data<<" ";
		path.push(top);
	}
	return;
}

void child_check(node * root, stack<node *> &path)
{
	if(root->left == NULL && root->right == NULL)
	{
		print_stack(path);
		cout<<"\n";
		return;
	}
	else
	{
		if(root->left!=NULL)
		{
			path.push(root->left);
			child_check(root->left, path);
			path.pop();
		}
		if(root->right!=NULL)
		{
			path.push(root->right);
			child_check(root->right, path);
			path.pop();
		}
	}
	return;
}

void root_leaf_paths(node * root)
{
	stack< node *> path;
	path.push(root);
	if(!path.empty())
	{
		node * top = path.top();
		if(top->left!= NULL)
		{
			path.push(top->left);
			child_check(top->left, path);
			path.pop();
		}
		if(top->right!= NULL)
		{
			path.push(top->right);
			child_check(top->right, path);
			path.pop();
		}
		path.pop();
	}
}

int main() {
	node * root = new node(4);
	node * l = new node(2);
	node * r = new node(5);
	node * ll= new node(1);
	root->left = l;
	root->right = r;
	root->left->left = ll;
	root_leaf_paths(root);
	return 0;
}
