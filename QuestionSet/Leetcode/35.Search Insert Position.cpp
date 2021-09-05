/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-05 17:18:42
 * @Description: Search Insert Position
 * @FilePath: /DSA/QuestionSet/Leetcode/35.Search Insert Position.cpp
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};