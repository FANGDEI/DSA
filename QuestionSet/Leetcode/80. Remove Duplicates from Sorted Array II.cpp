/*
 * @Author: FANG
 * @Date: 2021-09-06 20:29:52
 * @LastEditTime: 2021-09-06 20:29:52
 * @Description: Remove Duplicates from Sorted Array II
 * @FilePath: \DSA\QuestionSet\Leetcode\80.Remove Duplicates from Sorted Array II.cpp
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] != nums[len - 2]) nums[len++] = nums[i];
        }
        return len;
    }
};