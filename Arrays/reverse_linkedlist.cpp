//============================================================================
// Name        : reverse_linkedlist.cpp
// Description :
//============================================================================

#include<iostream>
#include<cstdio>
using namespace std;

struct node
{
	int data;
	node * next;
};

//recursive
struct node * reverse (struct node * current, struct node * prev)
{
	if(current->next == NULL )
	{
		current->next = prev;
		return current;
	}
	else
	{
		struct node * temp = reverse (current->next, current);
		current->next = prev;
		return temp;
	}
}
//iterative

void reverse(struct node * current)
{
	node * temp, *prev = NULL;
	while(current!=NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
}

int main()
{
	struct node * head;
	int a[] = {1,2,2,3,4};
	struct node *p , * q;
	q->data = a[0];
	for(int i =1;i<5;i++)
	{
		struct node * b;
		b->data = a[i];
		b->next = NULL;
		q->next = b;
		q = b;
	}

	p = head;
	q = p->next;
	p->next  = NULL;
	/*
	 * t = q->next
	 * q->next =p
	 * p = q
	 * q = t
	 */
	while(q!=NULL)
	{
		q = (node *) (p ^ q ^ (q->next) ^ (q->next = p) ^ (p = q));
	}
	head = p;
}

