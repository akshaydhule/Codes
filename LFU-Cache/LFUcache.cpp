//============================================================================
// Name        : LFU_Cache.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

struct Lnode
{
    int value;
    Lnode *next,*prev;
    Lnode(int a)
    {
    	this->value =a;
    	this->next = NULL;
    	this->prev = NULL;
    }
};

struct node
{
    int freq;
    Lnode *head, *tail;
    map<int, Lnode *> values;
    struct node *next, *prev;
};

class LFUCache {
    int capacity,curr;
    map<int, node *> freqNode;
    map<int, int> valueNode;
    node * root;

public:

    LFUCache(int cap) {
        this->curr = 0;
        this->capacity = cap;
        this->root = new node();
        root->head = NULL;
        root->tail = NULL;
        root->next = NULL;
        root->prev = NULL;
    }

    int get(int key) {
    	if (valueNode.find(key) == valueNode.end())
    		return -1;
        int freq =valueNode[key]; // freq
        node * temp = freqNode[freq]; // point

        Lnode * tail = temp->values[key];
        //remove 'node' from that list
        if (temp->values.size() == 1)
        {
        	node *temp1 = temp;
        	freqNode.erase(temp->freq);
        	if (temp->next == NULL && temp == root) // single node
        	{
        		root = NULL;
        		temp = NULL;
        	}
        	else
        	{
				temp->values.erase(key); //remove key from temp node
				if(temp1->next== NULL){ //tail of list
					temp = temp->prev;
					temp->prev->next = NULL;
				}
				else if(temp1->prev == NULL){ // head of list
					temp = temp->next;
					root = temp;
				}
				else{
					temp = temp->prev;
					temp1->prev->next = temp1->next;
					temp1->next->prev = temp1->prev;
				}
        	}
        	delete temp1;
        }
        //if it has more than one 'Lnode' in temp
        else //remove Lnode from list
        {
			temp->values.erase(key);
			if(tail == temp->head) // if Lnode is head
			{
				temp->head = temp->head->next;
			}
			else if(tail == temp->tail)//if Lnode is tail
			{
				temp->tail = temp->tail->prev;
			}
			else //else case
			{
				tail->prev->next = tail->next;
				tail->next->prev = tail->prev;
			}
        }
        int value = tail->value;
        valueNode.erase(value);
        freq++;
        //node addition
        Lnode * newn = new Lnode(value);
        node * newnode = new node();
		newnode->freq = freq;
		newnode->values.insert(make_pair(key, newn));
        if(root == NULL)
        {
        	newnode->head = newn;
			newnode->tail = newn;
			root = newnode;
			delete tail;
			freqNode.insert(make_pair(freq, newnode));
			return value;
        }
        else
        {
			if(temp->freq == freq)
			{
				temp->next->values.insert(make_pair(key, newn));
				valueNode.insert(make_pair(key, freq));
				temp->next->tail->next = newn;
				temp->next->tail = newn;
				delete newnode;
				delete newn;
				return value;
			}
			//next freq node present
			else if (temp->next != NULL && temp->next->freq == freq)
			{
				temp->next->values.insert(make_pair(key, newn));
				newn->next = temp->next->head;
				temp->next->head->prev = newn;
				temp->next->head = newn;
				valueNode.insert(make_pair(key, freq));
				delete newnode;
				delete newn;
				return value;
			}
			//if last node in list and add new node
			if(temp->next == NULL && temp->freq < freq)
			{
				newnode->head = newn;
				newnode->tail = newn;
				temp->next = newnode;
				newnode->prev = temp;
				newnode->next = NULL;
				valueNode.insert(make_pair(key, freq));
				freqNode.insert(make_pair(freq, newnode));
			}
			else//insert new node in-between
			{
				newnode->head = newn;
				newnode->tail = newn;
				newnode->next = temp;
				if(temp != root)
					temp->prev->next = newnode;
				else
				{
					newnode->prev = NULL;
					root = newnode;
				}
				temp->prev = newnode;
				valueNode.insert(make_pair(key, freq));
				freqNode.insert(make_pair(freq, newnode));
			}
			delete newn;
        return value;
        }
    }

    void set(int key, int value) {
        if (freqNode.find(key)!= freqNode.end())
        {
            freqNode[key]->values[key]->value = value; // updates the value
        }
        else
        {
            if(capacity == curr) // drop least freq and least recent node
            {
            	int valueDelete = -1;
            	//drop complete node
            	if(root->values.size() == 1)
            	{
            		node * temp = root;
            		root = root->next;
            		root->prev = NULL;
            		valueDelete = temp->tail->value;
            		freqNode.erase(temp->freq);
            		delete temp;
            	}
            	else
            	{
            		//drop one Lnode from root node
					Lnode * tail = root->tail;
					root->values.erase(tail->value);
					valueDelete = tail->value;
					cout<<"dropping element : "<< tail->value<<endl;
					root->tail = root->tail->prev;
					root->tail->next = NULL;
					delete tail;
            	}
                valueNode.erase(valueDelete);
                curr--;
            }
            Lnode * newnode = new Lnode(value);
            //no root
            if(root->values.empty() == true)
            {
            	root->freq = 1;
            	root->head = newnode;
            	root->tail = newnode;
            	root->values.insert(make_pair(key,newnode));
            	freqNode.insert(make_pair(1,root));
            }
            //freq 1 root available
            else if(root->freq == 1) // freq 1
            {
                newnode->next = root->head; // push at beginning of root node's list
                root->head->prev = newnode;
                newnode->prev = NULL;
                root->head = newnode;
                root->values.insert(make_pair(key, newnode));
                //freqNode.insert(make_pair(1,root));
            }
            //freq 1 node not available
            else // complete new node structure with one element head and tail pointing to it.
            {   //root points to newroot
                node *newroot = new node();
                newroot->freq = 1;
                newroot->head = newnode;
                newroot->tail = newnode;
                newroot->values.insert(make_pair(key, newnode));
                newroot->next = root;
                root->prev = newroot;
                newroot->prev = NULL;
                root = newroot;
                freqNode.insert(make_pair(1,root));
            }
            valueNode.insert(make_pair(key, 1));
            curr++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */

int main() {
	int capacity =2;
	LFUCache * obj = new LFUCache(capacity);
	obj->set(1,1);
	obj->set(2,2);
	cout<<obj->get(2)<<endl;
	obj->set(3,3);
	cout<<obj->get(2)<<endl;
	cout<<obj->get(1)<<endl;
	cout<<obj->get(3)<<endl;
	return 0;
}
