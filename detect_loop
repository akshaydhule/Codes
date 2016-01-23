//============================================================================
// Name        : detect_loop.cpp
// Description : Detect a loop in linked List
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

void push (struct node **head, int value)
{
	struct node * newnode = (struct node *)malloc (sizeof(struct node ));
	newnode->data = value;
	newnode->next = *head;
	*head = newnode;
}

void detect_loop(struct node *head)
{
	struct node * slow = head;
	struct node * fast = head;
	while (slow!=NULL && fast!=NULL && fast->next!=NULL)
	{
		if (slow == fast)
		{
			cout<< "loop found at: "<<fast->data;
			return;
		}
		slow = slow->next;
		fast = fast->next;
	}
	cout<<"no loop found";
}

int main() {
	struct node * head = NULL;
	push(&head, 20);
	push(&head, 10);
	push(&head, 15);
	push(&head, 11);
	head->next->next->next->next = head->next;
	detect_loop(head);
	return 0;
}
