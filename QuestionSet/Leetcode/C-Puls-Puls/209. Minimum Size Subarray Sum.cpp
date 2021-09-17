/*
 * @Author: FANG
 * @Date: 2021-09-06 22:50:44
 * @LastEditTime: 2021-09-06 22:50:45
 * @Description: Minimum Size Subarray Sum
 * @FilePath: \DSA\QuestionSet\Leetcode\209. Minimum Size Subarray Sum.cpp
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int s, e;
        s = e = 0;
        int ans = 0x3f3f3f3f, sum = 0;
        while (e < nums.size()) {
            sum += nums[e];
            while (sum >= target) {
                ans = min(ans, e - s + 1);
                sum -= nums[s];
                s++;
            }
            e++;
        }
        return ans == 0x3f3f3f3f ? 0 : ans;
    }
};