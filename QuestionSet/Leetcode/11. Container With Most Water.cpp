/*
 * @Author: FANG
 * @Date: 2021-09-06 23:34:12
 * @LastEditTime: 2021-09-06 23:34:12
 * @Description: Container With Most Water
 * @FilePath: \DSA\QuestionSet\Leetcode\11. Container With Most Water.cpp
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -0x3f3f3f3f;
        int s = 0, e = height.size() - 1;
        while (s < e) {
            int d = e - s;
            int g = min(height[s], height[e]);
            ans = max(g * d, ans);
            if (height[e] > height[s]) s++;
            else if (height[e] <= height[s]) e--;
        }
        return ans;
    }
};