//============================================================================
// Name        : LL-ReverseLL.cpp
// Description : reverse a linked list
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

node * reverseLL(node * head)
{
	node * curr = head, * prev = NULL;
	while(curr!=NULL)
	{
		node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

int main() {
	node * head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	node * newlist = reverseLL(head);
	while(newlist!=NULL)
	{
		cout<<newlist->data<<" ";
		newlist = newlist->next;
	}
	return 0;
}
