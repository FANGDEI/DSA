/*
 * @Author: FANG
 * @Date: 2021-09-17 17:01:31
 * @LastEditTime: 2021-09-17 17:01:32
 * @Description:Reshape the Matrix
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\566. Reshape the Matrix.cpp
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;
        
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            ans[i / c][i % c] = nums[i / n][i % n];
        }
        return ans;
    }
};