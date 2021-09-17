/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-09 21:01:27
 * @Description: Climbing Stairs
 * @FilePath: /DSA/QuestionSet/Leetcode/70. Climbing Stairs.cpp
 */
class Solution {
public:
    int climbStairs(int n) {
        int f[n + 5];
        f[1] = 1, f[2] = 2;
        for (int i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};