/*
 * @Author: FANG
 * @Date: 2021-10-13 11:22:06
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
    bool findTarget(TreeNode* root, int k) {
        inorderTravel(root);
        // [1] 2
        // map<int, int> m;
        // for (int i = 0; i < v.size(); i++) {
        //     m[v[i]]++;
        //     // cout << v[i] << " ";
        // }
        // for (int i = 0; i < v.size(); i++) {
        //     if (m[k - v[i]] != 0) return true;
        // }
        // return false;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (v[i] + v[j] == k && i != j) return true;
            }
        }
        return false;
    }
    void inorderTravel(TreeNode *root) {
        if (root) {
            inorderTravel(root->left);
            v.push_back(root->val);
            inorderTravel(root->right);
        }
    }
};