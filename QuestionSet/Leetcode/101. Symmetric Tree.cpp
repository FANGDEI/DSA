/*
 * @Author: FANG
 * @Date: 2021-09-13 12:49:55
 * @LastEditTime: 2021-09-13 12:49:56
 * @Description: Symmetric Tree
 * @FilePath: \DSA\QuestionSet\Leetcode\101. Symmetric Tree.cpp
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return judgeSymmetric(root->left, root->right);
    }
private:
    bool judgeSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr and right == nullptr) return true;
        if (!left and right) return false;
        else if (!right and left) return false;
        else if (left->val != right->val) return false;
        return judgeSymmetric(left->left, right->right) and judgeSymmetric(left->right, right->left);
    }
};