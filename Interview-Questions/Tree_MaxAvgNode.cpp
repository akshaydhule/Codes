/*
//============================================================================
// Name        : Tree_MaxAvgNode.cpp
// Description : Given tree of nodes and values
 * return max node of maximum average subtree
 * example:
 *        1
 *      2   4
 *    10 3
 *
 * Output:
 *  10
 * example:
 *        1
 *      2   8
 *    10 3
 *
 * Output:
 *  8
//============================================================================
*/
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

class node
{
public:
	int value;
	node *left, *right;
	node(int val)
	{
		this->value = val;
		this->right = NULL;
		this->left = NULL;
	}
};

class Cnode
{
public:
	int sum, n;
	float avg;
	Cnode (int a, int b)
	{
		this->sum = a;
		this->n = b;
		this->avg = a/b;
	}
};

node * maxnode1(node * root, map<node *, Cnode *> &nodeavg)
{
	if(root == NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		nodeavg.insert(make_pair(root, new Cnode(root->value, 1)));
		return root;
	}

	node *leftmax = maxnode1(root->left, nodeavg);
	node *rightmax = maxnode1(root->right, nodeavg);
	node * max = root;
	if(root->left!= NULL && root->right != NULL)
	{
		int sum = root->value + nodeavg[root->left]->sum + nodeavg[root->right]->sum;
		int n = 1 + nodeavg[root->left]->n + nodeavg[root->right]->n;
		nodeavg.insert(make_pair(root, new Cnode(sum,n)));
		float avg = sum/n;
		float leftavg = nodeavg[root->left]->avg;
		float rightavg = nodeavg[root->right]->avg;
		if (avg>=leftavg && avg>=rightavg)
		{
			max = max->value>leftmax->value? max: leftmax;
			max = max->value>rightmax->value? max: rightmax;
		}
		else
		{
			if(leftavg == rightavg)
				max = leftmax->value > rightmax->value? leftmax:rightmax;
			else
				max = leftavg>rightavg? leftmax: rightmax;
		}
		return max;
	}
	else
	{
		node *temp = root->left!= NULL ? root->left:root->right;
		node *childmax = root->left!= NULL ? leftmax: rightmax;
		int sum = (root->value + nodeavg[temp]->sum);
		int n = nodeavg[temp]->n+1;
		nodeavg.insert(make_pair(root, new Cnode(sum, n)));
		float avg = sum/n;
		int tempavg = nodeavg[temp]->avg;
		if(avg>tempavg)
		{
			max = max->value>childmax->value ? max:childmax;
		}
		else
			max = childmax;
		return max;
	}

}

node * maxnode(node * root)
{
	map<node *, Cnode *> nodeavg;
	return maxnode1(root, nodeavg);
}

int main() {
	node * root = new node(2);
	root->left = new node(3);
	root->right = new node (8);
	root->left->left = new node(10);
	root->left->right = new node(1);
	node * maxnod = maxnode(root);
	cout<<maxnod->value;
	return 0;
}
