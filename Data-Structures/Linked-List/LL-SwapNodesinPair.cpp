//============================================================================
// Name        : LL-SwapNodesinPair.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Given a linked list, swap every two adjacent nodes and return its head.
//============================================================================

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* cur = head;
        if(head->next == NULL)
            return head;
        ListNode* newlist = new ListNode(-1);
        ListNode* prev = newlist;
        while(cur!=NULL && cur->next!=NULL)
        {
            prev->next = cur->next;
            prev = prev->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = cur->next;
            prev = prev->next;
        }
        return newlist->next;
    }
};

int main() {
	Solution s;
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	s.swapPairs(root);
	return 0;
}
