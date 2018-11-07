//============================================================================
// Name        : sumoftwolinkedlist.cpp
// Description : Given two numbers represented by two linked lists return sum
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

struct node * newnode(int data)
{
	struct node * node = new node;
	node->data= data;
	node->next = NULL;
	return (node);
}

int size(struct node * node)
{
	int count=0;
	while(node!=NULL)
	{
		node=node->next;
		count++;
	}
	return count;
}

void addremaining(struct node * p1,int dist,struct node **final,int *carry)
{
	if(dist==NULL)
		return;
	else
		addremaining(p1->next,dist--,final,carry);
	struct node * val;
	int d=0;
	if(carry!=0)
		d = *carry + p1->data;
		val->data = d % 10;
		*carry = d/10;
		val->next = *final;
		*final = val;
}
struct node *addlist (struct node * first, struct node *second, int **final)
{
	int l1=0,l2=0;
	l1 = size(first);
	l2 = size(second);
	int carry=0;
	struct node * p1 = new node;
	struct node * p2 = new node;
	if(l1==l2)
		*final = sum(first, second, &carry);
	else
	{
		int dist = abs(l1-l2);
		if(l1>l2)
			{p1 = first;p2=second;}
		else
			{p1 = second;p2=first;}
		struct node * current = p1;
		while(dist!=0)
		{
			current= current->next;
			dist--;
		}
		*final = sum(current, p2, &carry);
		addremaining(p1,dist,final,&carry);
	}
}
struct node * sum(struct node * first, struct node *second, int * carry)
{
	if(first==NULL && second == NULL)
		return NULL;

	struct node * add = new node;
	if(first!=NULL && second != NULL)
		add->next = sum(first->next,second->next,carry);

	int val = first->data + second->data +carry;
	add->data = val%10;
	carry = val/10;
	return add;
}

int main() {
	struct node *first = newnode(2);
	first->next = newnode(4);
	struct node *second = newnode(3);
	second->next = newnode(4);
	struct node * add = sum(first, second,0);

	return 0;
}
