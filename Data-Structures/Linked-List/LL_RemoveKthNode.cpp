//============================================================================
// Name        : LL_RemoveKthNode.cpp
// Description : LL remove every kth node and return head of new LL
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

void print_LL(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

node* build_LL(int size)
{
	int count = 1;
	node* head = new node(1);
	node* new_head = head;
	while(count <size)
	{
		count += 1;
		new_head->next = new node(count);
		new_head = new_head->next;
	}
	return head;
}

node* new_LL(node* head, int k)
{
	node* new_head = head;
	int count = 1;
	while(new_head != NULL)
	{
		while(count<k-1 && new_head != NULL)
		{
			new_head = new_head->next;
			count += 1;
		}
		if(count == k-1 && new_head != NULL)
		{
			node* temp;
			if(new_head->next != NULL)
				temp = new_head->next;
			if(temp->next!= NULL)
				new_head->next = temp->next;
			free(temp);
			new_head = new_head->next;
			count = 1;
		}
	}
	return head;
}

node* modify_LL(node* head, int k)
{
	node* prev = NULL;
	node* current = head;
	int count = 1;
	while(current != NULL)
	{
		count += 1;
		prev = current;
		current = current->next;
		if(count%k == 0)
		{
			node* temp = current;
			prev->next = current->next;
			free(temp);
		}
	}
	return head;
}

int main() {
	node* head = build_LL(10);
	print_LL(head);cout<<endl;
	//node* new_head = new_LL(head, 3);
	node* new_head = modify_LL(head, 3);
	print_LL(new_head);
	return 0;
}
