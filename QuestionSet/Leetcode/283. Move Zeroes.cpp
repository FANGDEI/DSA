/*
 * @Author: FANG
 * @Date: 2021-09-06 20:36:53
 * @LastEditTime: 2021-09-06 20:37:13
 * @Description: Move Zeroes
 * @FilePath: \DSA\QuestionSet\Leetcode\283.Move Zeroes.cpp
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) nums[slow++] = nums[fast];
        }
        for (slow; slow < fast; slow++) {
            nums[slow] = 0;
        }
    }
};