/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-05 17:45:08
 * @Description: Maximum Subarray
 * @FilePath: /DSA/QuestionSet/Leetcode/53.Maximum Subarray.cpp
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum, ThisSum;
        maxSum = ThisSum = 0;
        maxSum = nums[0]; // Input: [-1]
        for (int i = 0; i < nums.size(); i++) {
            ThisSum += nums[i];
            if (ThisSum > maxSum) maxSum = ThisSum;
            if (ThisSum < 0) ThisSum = 0;
        }
        return maxSum;
        // return maxSum > 0 ? maxSum : 0;
    }
};