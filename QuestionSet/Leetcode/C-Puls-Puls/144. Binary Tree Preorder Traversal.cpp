/*
 * @Author: FANG
 * @Date: 2021-10-10 23:33:09
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
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
        preTraversal(root);
        return v;
    }
    void preTraversal(TreeNode *root) {
        if (root == nullptr) return ;
        v.push_back(root->val);
        preTraversal(root->left);
        preTraversal(root->right);
    }
};