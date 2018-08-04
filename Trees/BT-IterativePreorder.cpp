//============================================================================
// Name        : BT-IterativePreorder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode * left, *right;
	TreeNode(int d)
	{
		val = d;
		left = NULL;
		right = NULL;
	}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> output;
    stack<TreeNode *> order;
    if(root == NULL)
        return output;
    order.push(root);

    while(!order.empty())
    {
        TreeNode* Top = order.top();
        order.pop();
        if(Top->right != NULL)
            order.push(Top->right);
        if(Top->left != NULL)
            order.push(Top->left);
        output.push_back(Top->val);
    }
    return output;
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> order;
    vector<int> output;
    if(root == NULL)
        return output;
    bool status = true;
    TreeNode* Top = root;
    while(status)
    {
        if(Top != NULL)
        {
            order.push(Top);
            Top = Top->left;
        }
        else
        {
        	if(!order.empty())
        	{
        		Top = order.top();
        		output.push_back(Top->val);
        		order.pop();
        		Top = Top->right;
        	}
            else
            {
            	status = false;
            }
        }
    }
    return output;
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	vector<int> output = inorderTraversal(root);
	for(int i=0; i<output.size(); i++)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}
