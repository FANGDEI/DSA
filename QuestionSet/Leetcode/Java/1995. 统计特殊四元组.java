/*
 * @Author: FANG
 * @Date: 2021-12-29 00:04:03
 */
class Solution {
    public int countQuadruplets(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    for (int h = k + 1; h < nums.length; h++) {
                        if (nums[i] + nums[j] + nums[k] == nums[h]) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
}