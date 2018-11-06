//============================================================================
// Name        : LL-ReverseSublist.cpp
// Description : rotate with window k
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

node* reverseLL(node* head, int k)
{
	node* curr = head, *prev = NULL, *temp = head;
	node* prevlistHead = NULL, *currlistTail = NULL, *currlistHead = NULL;
	int n = 0;
	while(temp!=NULL)
	{
		temp = temp->next;
		n++;
	}
	int iterations = n/k;
	int i = 0, j = 0;
	while(i<iterations)
	{
		prevlistHead = currlistHead;
		currlistTail = curr;
		while(j<k)
		{
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
			j++;
		}
		currlistTail->next = prevlistHead;
		currlistHead = prev;
		j=0;
		i++;
	}
	if(curr != NULL)
	{
		while(curr!=NULL)
		{
			temp = curr->next;
			curr->next = currlistHead;
			currlistHead = curr;
			curr = temp;
		}
		return currlistHead;
	}
	return prev;
}

node* reverse(node* p, node* q) {
	node* t = NULL;
	while (p != q) {
		node* s = p->next;
		p->next = t;
		t = p;
		p = s;
	}
	return t;
}

node* reverseKGroup(node* head, int k) {
	node* first = NULL;
	node* last = NULL;
	node* p = head;
	while (p) {
		node* q = p;
		int n = k;
		for (; n && q; n--) q = q->next;
		if (n == 0) {
			node* t = reverse(p, q); // q can be equal to NULL
			if (first)
				last->next = t;
			else
				first = t;
			p->next = q;
			last = p;
		} else {
			// do nothing, q == NULL
			if (!first)
				first = p;
		}
		p = q;
	}
	return first;
}


int main() {
	node * head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = new node(6);
	head->next->next->next->next->next->next = new node(7);
	head->next->next->next->next->next->next->next = new node(8);
	head->next->next->next->next->next->next->next->next = new node(9);
	node* newlist = reverseKGroup(head, 3);
	while(newlist!=NULL)
	{
		cout<<newlist->data<<" ";
		newlist = newlist->next;
	}
	return 0;
}
