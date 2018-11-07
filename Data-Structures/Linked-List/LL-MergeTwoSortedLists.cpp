//============================================================================
// Name        : LL-MergeTwoSortedLists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

node * mergedlist(node *l1, node* l2)
{
	node* newlist = new node(-1);
	node*prev = newlist;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->data <l2->data)
		{
			node *next = l1->next;
			prev->next = l1;
			l1 = next;
		}
		else
		{
			node *next = l2->next;
			prev->next = l2;
			l2 = next;
		}
		prev = prev->next;
	}

	prev->next = l1 == NULL ? l2 : l1;

	return newlist->next;
}

int main() {
	node * l1 = new node(1);
	node * l2 = new node(2);
	node* l = mergedlist(l1, l2);
	return 0;
}
