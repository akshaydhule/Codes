//============================================================================
// Name        : LL-ListZipping.cpp
// Description : list zipping given a LL of integers
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

node *reverseLL(node *head)
{
	node *curr = head, *prev = NULL;
	while(curr!=NULL)
	{
		node *temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

node *listZipping(node *head)
{
	node *SecondListHead = NULL, *slow = head, *fast = head;
	while(fast->next!=NULL && fast!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	SecondListHead = reverseLL(slow->next);
	slow->next = NULL;
	node *currListNode = head;
	while(SecondListHead != NULL)
	{
		node *temp = SecondListHead->next;
		SecondListHead->next = currListNode->next;
		currListNode->next = SecondListHead;
		currListNode = currListNode->next->next;
		SecondListHead = temp;
	}
	return head;
}

int main() {
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	node *newlist = listZipping(head);
	while(newlist!=NULL)
	{
		cout<<newlist->data<<" ";
		newlist = newlist->next;
	}
	return 0;
}
