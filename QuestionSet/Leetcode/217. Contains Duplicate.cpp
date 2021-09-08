/*
 * @Author: FANG
 * @Date: 2021-09-08 10:37:20
 * @LastEditTime: 2021-09-08 10:37:21
 * @Description: Contains Duplicate
 * @FilePath: \DSA\QuestionSet\Leetcode\217. Contains Duplicate.cpp
 */
// set 去重也可
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};