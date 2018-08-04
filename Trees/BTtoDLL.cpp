//============================================================================
// Name        : BTtoDLL.cpp
// Description : Convert a Binary Tree to a Circular Doubly Link List
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node * left, *right;
	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

node * BuildDLL(node *lefthead, node *righthead)
{
	if(lefthead == NULL)
		return righthead;
	if(righthead == NULL)
		return lefthead;

	node * leftlast = lefthead->left;
	node * rightlast = righthead->left;

	//middle chain connection
	leftlast->right = righthead;
	righthead->left = leftlast;

	//end chain connection
	rightlast->right = lefthead;
	lefthead->left = rightlast;
	return lefthead;

}


node * BTtoDLL(node * head)
{
	if(head == NULL)
		return NULL;

	node * leftlist = BTtoDLL(head->left);
	node * rightlist = BTtoDLL(head->right);

	head->left = head->right = head;

	return BuildDLL(BuildDLL(leftlist, head), rightlist);

}

void printlist(node * head)
{
	node * root = head;
	do
	{
		cout<<head->data<<" ";
		head = head->right;
	}while(head != root);
}

int main() {
	node * head = new node(3);
	head->left = new node(2);
	head->left->left = new node(1);
	head->left->right = new node (4);
	head->right = new node (5);
	head->right->left = new node(6);
	head->right->right = new node(7);
	node * root = BTtoDLL(head);
	printlist(root);
	return 0;
}
