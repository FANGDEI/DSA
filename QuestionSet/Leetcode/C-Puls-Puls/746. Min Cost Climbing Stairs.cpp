/*
 * @Author: FANG
 * @Date: 2021-09-17 17:17:51
 * @LastEditTime: 2021-09-17 17:17:52
 * @Description: Min Cost Climbing Stairs
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\746. Min Cost Climbing Stairs.cpp
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f[1005];
        f[0] = cost[0];
        f[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            f[i] = min(f[i - 1] + cost[i], f[i - 2] + cost[i]);
        }
        return min(f[cost.size() - 1], f[cost.size() - 2]);
    }
};