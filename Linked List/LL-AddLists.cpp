//============================================================================
// Name        : LL-AddTwoLLists.cpp
// Description : Hello World in C++, Ansi-style
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

int getsize(node* head)
{
	node* temp = head;
	int size = 0;
	while(temp!=NULL)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

void swapPointers(node** head1, node** head2)
{
	node** temp = head1;
	head1 = head2;
	head2 = head1;
}

node* SameSizeSum(node* l1, node* l2, int * carry)
{
	if(l1 == NULL)
		return NULL;
	else
	{
		node* result = new node(0);
		result->next = SameSizeSum(l1->next, l2->next, carry);
		int sum = l1->data + l2->data + *carry;
		result->data = (sum % 10);
		*carry = (sum/10);
		return result;
	}
}

node* addCarry(node* head, node* tail, node* SameSizeresult, int* carry)
{
	if(head == tail)
		return SameSizeresult;
	else
	{
		node* result;
		result->next = addCarry(head->next, tail, SameSizeresult, carry);
		int sum = head->data + *carry;
		*carry = sum/10;
		result->data = sum % 10;
		return result;
	}
}

node* addLists(node* l1, node* l2)
{
	int size1 = getsize(l1);
	int size2 = getsize(l2);
	node* result;
	if(size1 == 0 && size2 == 0)
		return result;
	if(size1 == 0)
		return l2;
	if(size2 == 0)
		return l1;
	int carry = 0;

	if(size1 == size2)
		result = SameSizeSum(l1, l2, &carry);

	else
	{
		int diffCount = abs(size1-size2);
		if(size1<size2)
			swapPointers(&l1, &l2);

		int i = 0;
		node* temp = l1;
		while(i<diffCount)
		{
			temp = temp->next;
			i++;
		}

		node* SameSizeresult = SameSizeSum(temp, l2, &carry);

		result = addCarry(l1, temp, SameSizeresult, &carry);

		if(carry!=0)
		{
			node* head = new node(carry);
			head->next = result;
		}
	}
	return result;
}

void printlist(node* head)
{
	node* temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
}


int main() {
	node* LList1 = new node(1);
	LList1->next = new node(2);
	LList1->next->next = new node(3);
	node* LList2 = new node(1);
	LList2->next = new node(2);
	node*result = addLists(LList1, LList2);
	printlist(result);
	return 0;
}
