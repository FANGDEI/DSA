/*
 * @Author: FANG
 * @Date: 2021-10-31 00:06:55
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    // [3,9,20,15,7] pre
    // [9,3,15,20,7] in
    TreeNode* build(vector<int> &pre, vector<int> &in, int x, int y, int m, int n) {
        if (x > y || m > n) return nullptr;
        TreeNode *root = new TreeNode(pre[x]);
        int j;
        for (j = m; j <= n; j++) if (pre[x] == in[j]) break;
        int leftNum = j - m;
        root->left = build(pre, in, x + 1, x + leftNum, m, j - 1);
        root->right = build(pre, in, x + leftNum + 1, y, j + 1, n);
        return root;
    }
};