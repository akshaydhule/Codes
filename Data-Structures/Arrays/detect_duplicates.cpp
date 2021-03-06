//============================================================================
// Name        : detect_duplicates.cpp
// Description : detect & remove duplicates in an sorted linked list
//============================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>



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

void print(struct node *head )
{

	while (head!=NULL)
	{
		cout <<head->data;
		head=head->next;
	}
}

void detect_duplicates(struct node ** head)
{
	struct node * pointer = *head;
	struct node * node=NULL;
	while (pointer->next!=NULL)
	{
		if (pointer->data == pointer->next->data)
		{
			node = pointer->next->next;
			delete(pointer->next);
			pointer->next = node;
		}
		else
		{
			pointer=pointer->next;
		}
	}
	cout<<"\n";
	print(*head);
}
void sortlist(struct node ** head)
{
	struct node *pointer = *head;
	int i=0;
	int n=0;
	int * a = (int * )malloc (sizeof(int));
	while (pointer!=NULL)
	{
		a[i] = pointer->data;
		pointer = pointer->next;
		i++;
	}
	std::sort(a,a+i);
	pointer = *head;
	for (n=0;n<i;n++)
	{
		pointer->data = a[n];
		pointer = pointer->next;
	}
	delete a;
}

int main() {
	struct node * head = NULL;
		push(&head, 10);
		push(&head, 10);
		push(&head, 15);
		push(&head, 17);
		push(&head, 20);
		push(&head, 21);
		push(&head, 25);
		print(head);
		cout<<"\n";
		sortlist(&head);
		cout<<"\n";
		print(head);
		detect_duplicates(&head);
	return 0;
}
