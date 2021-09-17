/*
 * @Author: FANG
 * @Date: 2021-09-12 23:22:41
 * @LastEditTime: 2021-09-12 23:22:42
 * @Description: Maximun Depth Binary Tree
 * @FilePath: \DSA\QuestionSet\Leetcode\104. Maximum Depth of Binary Tree.cpp
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};