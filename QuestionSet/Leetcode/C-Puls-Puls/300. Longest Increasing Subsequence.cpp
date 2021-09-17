/*
 * @Author: FANG
 * @Date: 2021-09-13 15:21:21
 * @LastEditTime: 2021-09-13 15:21:22
 * @Description: Longest Increasing Subsequence
 * @FilePath: \DSA\QuestionSet\Leetcode\300. Longest Increasing Subsequence.cpp
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int f[2505];
        for (int i = 0; i < nums.size(); i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) ans = max(ans, f[i]);
        return ans;
    }
};