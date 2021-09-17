/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-09 20:51:05
 * @Description: Rotate Array
 * @FilePath: /DSA/QuestionSet/Leetcode/189. Rotate Array.cpp
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k > nums.size()) k -= nums.size();
        int tmp[nums.size()];
        int i, j, q = 0;
        for (i = nums.size() - k; i < nums.size(); i++) tmp[q++] = nums[i];
        for (i = 0; i < nums.size() - k; i++) tmp[q++] = nums[i];
        for (i = 0; i < q; i++) nums[i] = tmp[i];
    }
};