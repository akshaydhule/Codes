//============================================================================
// Name        : tree_traversals.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;


struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode(int data)
{
	struct node * node = (struct node *) malloc (sizeof(struct node));
	node -> data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
};

void preorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->data;
	preorder(node->left);
	preorder(node->right);
}
void inorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}

	inorder(node->left);
	cout<<node->data;
	inorder(node->right);

}

void postorder(struct node * node)
{
	if(node==NULL)
	{
		return;
	}

	postorder(node->left);
	postorder(node->right);
	cout<<node->data;

}

int sizeoftree(struct node * root)
{
	if(root==NULL)
		return 0 ;
	else
		return (sizeoftree(root->left)+1+sizeoftree(root->right));
}

//mirror of tree
void mirror(struct node * node)
{
	if(node ==NULL)
		return;
	else
	{
		struct node *temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
//height of the tree
int height(struct node * node)
{
	int left;
	int right;
	if (node==NULL)
	{
		return 0;
	}
	else
	{
		left = height(node->left);
		right = height(node->right);
		if(left>right)
		{
			return (left+1);
		}
		else
			return (right+1);
	}
}
int matches(struct node *root, int a, int b)
{
	if (root==NULL)
		return 0;
	int match = matches(root->left,a,b)+matches(root->right,a,b);
	if(root->data==a || root->data == b)
		return 1+ match;
	else
		return match;
}

int common_ancestor(struct node *root, int a, int b)
{
	if(root==NULL)
		return 0;
	int match = matches(root->left, a, b);
	if(match ==1)
		return root->data;
	else if (match ==2)
	{
		return common_ancestor(root->left,a, b);
	}
	else
		return common_ancestor(root->right, a,b);
}
int main() {
	struct node *root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	/*cout<<"\npreorder:";
	preorder(root);
	cout<<"\npostorder:";
	postorder(root);
	cout<<"\ninorder:";
	inorder(root);
	mirror(root);
	cout<<"\ninorder:";
	inorder(root);
	cout<<"\nsizeoftree:"<<sizeoftree(root);
	cout<<"\nheight:"<<height(root);*/
	cout<<common_ancestor(root, 6,7);
	return 0;
}
