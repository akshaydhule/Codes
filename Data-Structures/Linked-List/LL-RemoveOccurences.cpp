//============================================================================
// Name        : LL-RemoveOccurences.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node * next;
	node(int d){
		data = d;
		next = NULL;
	}
};

node* removeOccurrences(node* head, int value){

	node * current = NULL;

	if(head->data == value){
		while(head != NULL && head->data == value){
			current = head;
			head = head->next;
			free(current);
		}
	}

	node * next = head;

	while(next != NULL){

		node* temp;

		while(next!= NULL && next->data != value){
			current = next;
			next = next->next;
		}

		if(next == NULL)
			return head;

		temp = next;
		next = next->next;
		current->next = next;
		free(temp);

	}

	return head;
}

void push(node* head_ref, int new_data)
{
    node* temp = head_ref;
    while(temp->next != NULL)
    	temp = temp->next;

    temp->next = new node(new_data);
}

void printList(node *head)
{
	node * node = head;
    while (node != NULL)
    {
        cout<< node->data << " -> ";
        node = node->next;
    }
    cout<<endl;
}

int main() {
	node *head = new node(2);
    push(head, 7);
    push(head, 2);
    push(head, 3);
    push(head, 2);
    push(head, 8);
    push(head, 1);
    push(head, 2);
    push(head, 2);
    push(head, 1);

    printList(head);

    head = removeOccurrences(head, 2);

    printList(head);

}
