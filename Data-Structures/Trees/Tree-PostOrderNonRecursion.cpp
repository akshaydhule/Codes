//============================================================================
// Name        : Tree-PostOrderNonRecursion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

//Type I
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

vector<int> InvertedPreorderList(node *root){
	vector<int> output = GetPreorderList(root);
	reverse(output.begin(), output.end());
	return output;
}

//Type II
vector<int> GetPostorderList(node *root){
	vector<int> output;
	stack<node *> path, waiting;
	waiting.push(root);
	while(!waiting.empty())
	{
		node *temp = waiting.top();
		waiting.pop();
		if(temp == NULL)
			continue;
		else
		{
			path.push(temp);
			waiting.push(temp->left);
			waiting.push(temp->right);
		}
	}
	while(!path.empty())
	{
		node *temp = path.top();
		path.pop();
		output.push_back(temp->data);
	}
	return output;
}

//Type III
vector<int> GetPostorderListI(node *root){
	stack<node *> path;
	vector<int> output;
	node * prev = NULL;
	path.push(root);
	while(!path.empty())
	{
		node * curr = path.top();
		//visiting up-down/1st time
		if(prev == NULL || prev->left == curr || prev->right == curr)
		{
			if(curr->left != NULL)
				path.push(curr->left);

			else if(curr->right != NULL)
				path.push(curr->right);
			//leaf node
			else
			{
				output.push_back(curr->data);
				path.pop();
			}
		}
		//call-back buttom-up: covered left side of the tree
		else if(curr->left == prev)
		{
			if(curr->right!=NULL)
				path.push(curr->right);
			//no right node
			else
			{
				output.push_back(curr->data);
				path.pop();
			}
		}
		//call-back : covered all childs
		else
		{
			output.push_back(curr->data);
			path.pop();
		}
		prev = curr;
	}
	return output;
}

int main() {
	node *root = new node(7);
	root->left = new node(3);
	root->right = new node(6);
	root->left->left = new node(1);
	root->left->right = new node(2);
	root->right->left = new node(4);
	root->right->right = new node(5);
	vector<int> output = GetPostorderListI(root);
	for(int i = 0; i<output.size(); i++)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}
