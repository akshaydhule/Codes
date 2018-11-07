//============================================================================
// Name        : TreeTraversal.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int value;
	node * left;
	node * right;
	node(int val) : value(val), left(NULL), right(NULL) {}
};

void printTraversal(node * root)
{
	if(root == NULL)
		return;
	else
	{
		cout<<root->value<<" ";
		if(root->left != NULL)
			printTraversal(root->left);
		if(root->right != NULL)
			printTraversal(root->right);
	}
}

int main() {
	node * root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	printTraversal(root);
	return 0;
}
