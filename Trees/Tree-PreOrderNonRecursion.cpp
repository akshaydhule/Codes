//============================================================================
// Name        : Tree-PreOrderNonRecursion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node
{
public:
	int data;
	node *left, *right;
	node(int d)
	{
		data = d;
		right = left = NULL;
	}
};

vector<int> GetPreorderList(node *root){
	vector<int> output;
	stack<node *> path;
	path.push(root);
	while(!path.empty())
	{
		node *temp = path.top();
		path.pop();
		if(temp == NULL)
			continue;

		output.push_back(temp->data);
		path.push(temp->right);
		path.push(temp->left);
	}
	return output;
}

int main() {
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	vector<int> output = GetPreorderList(root);
	for(int i = 0; i<output.size(); i++)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}
