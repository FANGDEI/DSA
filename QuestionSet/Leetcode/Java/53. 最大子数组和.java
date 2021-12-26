/*
 * @Author: FANG
 * @Date: 2021-12-26 23:48:19
 */
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 0) return 0;
        int res = nums[0];
        int[] f = new int[100005];
        f[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            f[i] = Math.max(f[i - 1] + nums[i], nums[i]);
            res = Math.max(f[i], res);
        }
        return res;
    }
}