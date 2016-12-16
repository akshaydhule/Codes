/*
//============================================================================
// Name        : BST_Detect_duplicate_trees.cpp
// Description : Find if a given binary tree has duplicate sub trees or not.
(Two leaf nodes of a parent do not count as subtree)
//============================================================================
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class node
{
public:
	char data;
	node * left, *right;
	node():data(0), left(NULL), right(NULL){}
	node(char d):data(d), left(NULL), right(NULL){}
};

string postorder(node * root, vector<string> &postOrder)
{
	if(!root->left && !root->right)
	{
		string s(1, root->data);
		return s;
	}
	else
	{
		string temp = "";
		if(root->left!= NULL)
			temp = postorder(root->left, postOrder);
		temp = temp + root->data;
		if(root->left!= NULL)
			temp = temp + postorder(root->right, postOrder);
		postOrder.push_back(temp);
		return temp;
	}
}

string inorder(node * root, vector<string> &inOrder)
{
	if(!root->left && !root->right)
	{
		string s(1, root->data);
		return s;
	}
	else
	{
		string temp = "";
		if(root->left!= NULL)
			temp = inorder(root->left, inOrder);
		temp = temp + root->data;
		if(root->left!= NULL)
			temp = temp + inorder(root->right, inOrder);
		inOrder.push_back(temp);
		return temp;
	}
}

bool detectduplicate(node * root)
{
	if(!root)
		return false;
	else
	{
		set<string> subtrees;
		vector<string> inOrder;
		vector<string> postOrder;
		node *temp = root;
		inorder(temp,inOrder);
		temp = root;
		postorder(temp, postOrder);
		for(int i=0;i<inOrder.size();i++)
		{
			string s = inOrder[i] + '-' + postOrder[i];
			if(subtrees.find(s)!= subtrees.end())
			{
				return true;
			}
			else
				subtrees.insert(s);
		}
		return false;
	}
}

int main() {
	node * root = new node('A');
	node * l = new node('B');
	node * r = new node('B');
	root->left = l; root->right = r;
	node * ll = new node('C');
	node * lr = new node('D');
	l->left = ll; l->right = lr;
	node * rl = new node('C');
	node * rr = new node('D');
	r->left = rl; r->right = rr;
	if(detectduplicate(root) == true)
		cout<<"true";
	else
		cout<<"false";
	return 0;
}
