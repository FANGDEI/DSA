/*
 * @Author: FANG
 * @Date: 2021-09-07 12:41:22
 * @LastEditTime: 2021-09-07 12:45:31
 * @Description: Median of Two Sorted Arrays
 * @FilePath: \DSA\QuestionSet\Leetcode\4. Median of Two Sorted Arrays.cpp
 */
class Solution {
public:
    /**
     * @Author: FANG
     * @description: find the Median, T: O(n + m), M : O(n + m)
     * @param {nums1, nums2}
     * @return {double}
     */    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int p1, p2, k = 0;
        p1 = p2 = 0;
        while (p1 < nums1.size() and p2 < nums2.size()) {
            if (nums1[p1] <= nums2[p2]) v.push_back(nums1[p1++]);
            else v.push_back(nums2[p2++]);
        }
        while (p1 < nums1.size()) v.push_back(nums1[p1++]);
        while (p2 < nums2.size()) v.push_back(nums2[p2++]);
        if (v.size() & 1) return 1.0 * v[v.size() / 2];
        else return 1.0 * (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
    }
};