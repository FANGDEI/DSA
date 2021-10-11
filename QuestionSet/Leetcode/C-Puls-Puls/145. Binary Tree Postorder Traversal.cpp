/*
 * @Author: FANG
 * @Date: 2021-10-10 23:35:41
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
    vector<int> postorderTraversal(TreeNode* root) {
        Traversal(root);
        return v;
    }
    void Traversal(TreeNode *root) {
        if (root == nullptr) return ;
        Traversal(root->left);
        // v.push_back(root->val);
        Traversal(root->right);
        v.push_back(root->val);
    }
};