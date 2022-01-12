/**
 * 103. Binary Tree Zigzag Level Order Traversal
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 * Example 3:
 * Input: root = []
 * Output: []
 * 
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> current, next;
        vector<vector<int>> output;
        if (!root) return output;
        current.push(root);
        /**
        1. current = current level of nodes from left to right
        2. reverse is the flag to reverse the list in alternate iterations
        3. next is the queue to iterate from left to right
        */
        bool reverse = false;
        while(!current.empty() || !next.empty()) {
            vector<int> currentList;
            while(!current.empty()) {
                auto curNode = current.front();
                if (curNode) {
                    currentList.push_back(curNode->val);
                    if (curNode->left) next.push(curNode->left);
                    if (curNode->right) next.push(curNode->right);
                }
                current.pop();
            }
            if (reverse) {
                std::reverse(currentList.begin(), currentList.end());
            }
            reverse = (reverse) ? false : true;
            output.push_back(currentList);
            current = next;
            while(!next.empty()) next.pop();
        }
        return output;
    }
};
