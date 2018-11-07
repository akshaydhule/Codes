//============================================================================
// Name        : BT-LCA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* CheckAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool pcheck, bool qcheck) {
    if(root == NULL)
        return NULL;

    TreeNode* left = CheckAncestor(root->left, p, q, pcheck, qcheck);
    TreeNode* right = CheckAncestor(root->right, p, q, pcheck, qcheck);

    //root is LCA
    if(left && right)
        return root;

    TreeNode* found = left!=NULL ? left : (right!=NULL ? right : NULL);

    //root is LCA and one of the node
    if(found != NULL && (root == p || root == q))
    {
        pcheck = qcheck = true;
        return root;
    }
    //Only 1 found
    if(found!=NULL)
        return found;

    if(root == p)
    {
        pcheck = true; return root;
    }
    if(root == q)
    {
        qcheck = true; return root;
    }
    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	bool pcheck = false, qcheck = false;
	return CheckAncestor(root, p, q, pcheck, qcheck);
}

TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
