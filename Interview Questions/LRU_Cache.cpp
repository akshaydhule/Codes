/*
//============================================================================
// Name        : LRU_Cache.cpp
// Description : Design and implement a data structure for
 * Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key
if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value
if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.
//============================================================================
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Qnode
{
public:
    unsigned int data,key;
    Qnode *prev, * next;
    Qnode(unsigned int key,unsigned int data)
    {
        this->key = key;
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache{
    private:
	unordered_map<int, Qnode*> mapping;
	Qnode *head;
	Qnode *tail;
	int capacity;
	int cur_size;
    void detach(Qnode * node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(Qnode * node)
    {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cur_size = 0;
        head = new Qnode(0,0);
        tail = new Qnode(0,0);
        head->next = tail;
        tail->prev = head;
    }
    int get(unsigned int key) {
        Qnode * temp = mapping[key];
        if(mapping.find(key)!=mapping.end())
        {
            detach(temp);
            attach(temp);
            return temp->data;
        }
        else
            return -1;

    }
    void set(unsigned int key,unsigned int value) {

        if(mapping.find(key)!=mapping.end())
        {
            Qnode * temp = mapping[key];
            detach(temp);
            temp->data = value;
            mapping[key] = temp;
            attach(temp);
        }
        else
        {
            Qnode * newnode = new Qnode(key, value);
            if(cur_size == capacity)
            {
                Qnode * newtail = tail->prev->prev;
                detach(tail->prev);
                tail->prev = newtail;
                cur_size--;
            }
            attach(newnode);
            cur_size++;
            mapping.insert(make_pair(key, newnode));
        }
    }
    void print()
    {
    	Qnode * temp = head->next;
    	while(temp!=tail)
    	{
    		cout<<temp->key <<" "<<temp->data<<"\n";
    		temp = temp->next;
    	}
    }
};

int main() {
	LRUCache schedule(4);
	schedule.set(1,2);
	schedule.print();
	schedule.set(2,2);
	schedule.print();
	schedule.set(3,2);
	schedule.print();
	schedule.set(4,2);
	schedule.print();
	schedule.set(5,1);
	schedule.set(6,3);
	schedule.print();
	return 0;
}
