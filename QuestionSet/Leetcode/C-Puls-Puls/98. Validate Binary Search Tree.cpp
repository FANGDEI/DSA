/*
 * @Author: FANG
 * @Date: 2021-10-13 11:11:35
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
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1]) return false;
        }
        return true;
    }
    void inOrder(TreeNode *root) {
        if (root) {
            inOrder(root->left);
            v.push_back(root->val);
            inOrder(root->right);
        }
    }
};