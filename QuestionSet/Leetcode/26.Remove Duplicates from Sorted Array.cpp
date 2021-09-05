/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-05 17:15:16
 * @Description: Remove Duplicates from Sorted Array
 * @FilePath: /DSA/QuestionSet/Leetcode/26.Remove Duplicates from Sorted Array.cpp
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() < 2) return nums.size();
       int slow = 0, fast = 1;
       for (; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast]) nums[++slow] = nums[fast];
       }
       return ++slow;
    }
};