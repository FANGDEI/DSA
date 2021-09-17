/*
 * @Author: FANG
 * @Date: 2021-09-06 20:40:38
 * @LastEditTime: 2021-09-06 20:40:38
 * @Description: Find Greatest Common Divisor of Array
 * @FilePath: \DSA\QuestionSet\Leetcode\1979. Find Greatest Common Divisor of Array.cpp
 */
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[nums.size()-1]);
    }
};