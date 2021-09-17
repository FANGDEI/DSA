/*
 * @Author: FANG
 * @Date: 2021-09-08 10:59:56
 * @LastEditTime: 2021-09-08 10:59:57
 * @Description: Path Sum
 * @FilePath: \DSA\QuestionSet\Leetcode\112. Path Sum.cpp
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        // if (root->val > targetSum) return false;
        if (root->val == targetSum and !root->left and !root->right) return true;
        bool lok =  hasPathSum(root->left, targetSum - root->val);
        bool rok = hasPathSum(root->right, targetSum - root->val);
        return lok || rok;
    }
};