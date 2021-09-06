/*
 * @Author: FANG
 * @Date: 2021-09-06 20:31:22
 * @LastEditTime: 2021-09-06 20:33:19
 * @Description: Merge Sorted Array
 * @FilePath: \DSA\QuestionSet\Leetcode\88.Merge Sorted Array.cpp
 */
// 双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sorted[m + n];
        int p1, p2, k;
        k = p1 = p2 = 0;
        while (p1 < m and p2 < n) {
            if (nums1[p1] <= nums2[p2]) sorted[k++] = nums1[p1++];
            else if (nums1[p1] > nums2[p2]) sorted[k++] = nums2[p2++];
        }
        while (p1 < m) sorted[k++] = nums1[p1++];
        while (p2 < n) sorted[k++] = nums2[p2++];
        for (int i = 0; i < k; i++) nums1[i] = sorted[i];
    }
};
// 加入到nums1后排序 (n + m)log(n + m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < m + n; i++) {
            if (i + m >= m + n) break;
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};