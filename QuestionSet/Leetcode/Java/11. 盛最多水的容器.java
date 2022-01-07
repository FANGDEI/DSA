/*
 * @Author: FANG
 * @Date: 2022-01-02 00:06:11
 */
class Solution {
    public int maxArea(int[] height) {
        int res = -0x3f3f;
        int l = 0, r = height.length - 1;
        while (l < r) {
            res = Math.max(res, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
}