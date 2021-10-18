/*
 * @Author: FANG
 * @Date: 2021-10-17 21:32:23
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
    int kthSmallest(TreeNode* root, int k) {
        inorderTravel(root);
        return v[k - 1];
    }
    void inorderTravel(TreeNode *root) {
        if (root == nullptr) return ;
        inorderTravel(root->left);
        v.push_back(root->val);
        inorderTravel(root->right);
    }
};