//============================================================================
// Name        : LL-CloneDLL.cpp
// Description : 1. create a duplicate whose any points to original
//				 2. create a copy node of current between current and next
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next, *any;
	node(int d)
	{
		data = d;
		next = any = NULL;
	}
};

node* CloneList(node* head)
{
	node* clone = new node(head->data);
	clone->any = head;
	node* temp1 = head->next;
	node* temp2 = clone;
	//1. create a ll && point clone any to original
	while(temp1!=NULL)
	{
		temp2->next = new node(temp1->data);
		temp2 = temp2->next;
		temp2->any = temp1;
		temp1 = temp1->next;
	}

	temp1 = head;
	temp2 = clone;
	//2. point original to clone
	while(temp1!=NULL)
	{
		node* current = temp1->next;
		temp1->next = temp2;
		temp1 = current;
		temp2 = temp2->next;
	}

	temp2 = clone;
	//3. update any pointer
	while(temp2!=NULL)
	{
		temp2->any = temp2->any->any->next;
		temp2 = temp2->next;
	}
	return clone;
}

node* CloneListII(node* head)
{
	//no node
	if(head == NULL)
		return NULL;
	//single node
	if(head->next == NULL)
	{
		node *newNode = new node(head->data);
		newNode->any >= head->any;
		return newNode;
	}
	//rest
	node *temp = head;

	while(temp!=NULL)
	{
		node *nextNode = temp->next;
		node *newNode = new node(temp->data);
		temp->next = newNode;
		newNode->next = nextNode;
		temp = nextNode;
	}
	//update any node
	temp = head;
	node *newList =head->next;
	while(temp!=NULL && newList!=NULL && temp->any!=NULL)
	{
		newList->any = temp->any->next;
		temp = temp->next->next;
	}

	node *current = head;
	node *finalList = head->next;
	newList = head->next;
	while(current!=NULL && current->next!=NULL)
	{
		current->next = newList? newList->next : newList;
		current = current->next;
		newList->next = current? current->next : current;
		newList = newList->next;
	}

	return finalList;
}

void printlist(node* head)
{
	node* temp = head;
	cout<<"data"<<"next"<<"any"<<endl;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<temp->next->data<<temp->any->data<<endl;
		temp = temp->next;
	}
	cout<<temp->data<<temp->any->data<<endl;
}

int main() {
	node* list = new node(1);
	list->next = new node(-1);
	//list->next->next = new node(3);
	//list->any = list->next->next;
	//list->next->any = list;
	//list->next->next->any =list->next;
	node* clone = CloneListII(list);
	printlist(clone);
	return 0;
}
