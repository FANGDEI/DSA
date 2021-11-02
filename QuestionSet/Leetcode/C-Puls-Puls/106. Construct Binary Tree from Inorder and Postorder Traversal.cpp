/*
 * @Author: FANG
 * @Date: 2021-10-30 23:57:52
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
    vector<int> in, post;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder, post = postorder;
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    // [x, y] 中 [m, n] 后
    // [9,3,15,20,7] in
    // [9,15,7,20,3] post
    TreeNode* build(int x, int y, int m, int n) {
        if (x > y || m > n) return nullptr;
        int j = 0;
        TreeNode *root = new TreeNode(post[n]);
        for (j = x; j <= y; j++) {
            if (in[j] == post[n]) break;
        }
        int leftNum = j - x;
        root->left = build(x, j - 1, m, m + leftNum - 1);
        root->right = build(j + 1, y, m + leftNum, n - 1);
        return root;
    }
};