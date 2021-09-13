/*
 * @Author: FANG
 * @Date: 2021-09-13 13:03:12
 * @LastEditTime: 2021-09-13 13:03:12
 * @Description: Binary Tree Level Order Traversal
 * @FilePath: \DSA\QuestionSet\Leetcode\102. Binary Tree Level Order Traversal.cpp
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if (root == nullptr) return v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;
            while (n--) {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            v.push_back(vec);
        }
        return v;
    }
};