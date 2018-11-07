/*
//============================================================================
// Name        : N-ary.cpp
// Description : build N-ary tree given array of numbers
 * serialize and De-serialize the array.
//============================================================================
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
#define n 5

class node
{
public:

	int val;
	node *child[n];
	int childcount;
	node(int a)
	{
		this->val = a;
		for(int i=0;i<n;i++)
		{
			this->child[i] = NULL;
		}
		this->childcount = 0;
	}
};

class nary
{
	node * root;
	public:
	nary(int a)
	{
		root = new node(a);
	}
	void insert(int val)
	{
		node * temp = root;
		node * temp1 = root;
		queue <node *> point;
		int i=0, j=0;
		point.push(root);
		while(1)
		{
			temp = point.front();
			point.pop();
			if(temp->childcount<5)
			{
				temp->child[temp->childcount++] = new node(val);
				return;
			}
			for(int i=0;i<n;i++)
			{
				temp1 = temp->child[i];
				if(temp1->childcount<5)
				{
					temp1->child[temp1->childcount++] = new node(val);
					return;
				}
				point.push(temp1->child[i]);
			}
		}
	}
	void build_nary(int *values, int size)
	{
		for(int i=0;i<size;i++)
		{
			insert(values[i]);
		}
	}
	void serialize()
	{
		node * temp = root;
		queue <node *> point;
		point.push(root);
		while(!point.empty())
		{
			temp = point.front();
			cout<< temp->val<<" ";
			point.pop();
			for(int i=0;i<temp->childcount;i++)
			{
				point.push(temp->child[i]);
			}
		}
		return;
	}
};


int main() {
	//serialize(a);
	nary root(2);
	int a[] = {3,4,5,6,7,8};
	root.build_nary(a, sizeof(a)/sizeof(a[0]));
	root.serialize();
	return 0;
}
