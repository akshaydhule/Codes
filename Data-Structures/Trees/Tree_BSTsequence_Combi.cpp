/*
//============================================================================
// Name        : Tree_BSTsequence_Combi.cpp
// Description : BST Sequences: A binary search tree was created by traversing
 * through an array from left to right and inserting each element.
 * Given a binary search tree with distinct elements,
 * print all possible arrays that could have led to this tree.
//============================================================================
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class node
{
public:
	int data;
	node *left, *right;
	node(int data)
	{
		this->data = data;
		this->left =NULL;
		this->right = NULL;
	}
};

void mergelists(list<int> &left, list<int> &right,
		vector< list<int> > &final, list<int> &prefix)
{
	list<int> :: iterator it;
	if(left.size() == 0 || right.size() == 0)
	{
		//add prefix, left and right to list and append list in final
		list<int> result (prefix.begin() , prefix.end());
		it = result.end();
		result.insert(it, left.begin(), left.end());
		it = result.end();
		result.insert(it, right.begin(), right.end());
		final.push_back(result);
		return;
	}

	//else for left list
	//
	int first = left.front();
	left.pop_front();
	prefix.push_back(first);
	mergelists(left, right, final, prefix);
	prefix.pop_back();
	left.push_front(first);

	//for right list
	int second = right.front();
	right.pop_front();
	prefix.push_back(second);
	mergelists(left, right, final, prefix);
	prefix.pop_back();
	right.push_front(second);
}

void  bstCombinations(node *root, vector< list<int> > &result)
{
	if (root == NULL)
	{
		list<int> res;
		result.push_back(res);
		return;
	}
	list<int> prefix;
	prefix.push_back(root->data);

	vector< list<int> > leftSeq;
	bstCombinations(root->left, leftSeq);
	vector< list<int> > rightSeq;
	bstCombinations(root->right, rightSeq);
	vector< list<int> > ::iterator itl, itr, it;
	for(itl = leftSeq.begin(); itl != leftSeq.end(); itl++)
	{
		for(itr = rightSeq.begin(); itr != rightSeq.end(); itr++)
		{
			vector< list<int> > final;
			mergelists(*itl, *itr, final, prefix);
			it = result.end();
			result.insert(it, final.begin(), final.end());
		}
	}
	return;
}



int main() {
	node *root = new node(4);
	root->left = new node(3);
	root->right = new node(2);
	root->left->left = new node(1);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	vector< list<int> > comb;
	bstCombinations(root, comb);
	list<int> :: iterator it;
	for(int i=0;i<comb.size();i++)
	{
		for(it = comb[i].begin(); it!= comb[i].end();it++)
		{
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}
