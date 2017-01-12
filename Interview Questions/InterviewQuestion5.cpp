/*
//============================================================================
// Name        : InterviewQuestion5.cpp
// Description :
 * 1. Find the node where cycle starts in a linked list
 * 2. Find the index when slow and fast pointer meet in terms of n
 * (length of list before cycle) and p ( length of loop in linked list).
	Let me meeting index is q then we should be able to find value of q when we pass n& p ,
	there shouldn't be any extra variable.
//============================================================================
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	int data;
	struct node * next;
};

struct node * newnode(int val)
{
	node * newnde = new node;
	newnde->data = val;
	newnde->next = NULL;
	return newnde;
}

struct node * meetingpoint(struct node * root)
{
	struct node * slow = root;
	struct node *fast = root;
	if(root==NULL || root->next==NULL)
		return NULL;
	while(fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	slow = root;
	while(slow!=fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int pos_from_start(int n, int p)
{
	return (n+p - (n%p));
}
int main() {
	struct node * root= newnode(8);
	root->next = newnode(7);
	struct node * start = root->next->next = newnode(6);
	root->next->next->next = newnode(5);
	root->next->next->next->next = newnode(4);
	root->next->next->next->next->next = start;
	struct node *meetingpt = meetingpoint(root);
	cout<<"\n the node where cycle starts: "<<meetingpt->data;
	cout<<"\n the position from the start: "<<pos_from_start(2,3);
	return 0;
}
