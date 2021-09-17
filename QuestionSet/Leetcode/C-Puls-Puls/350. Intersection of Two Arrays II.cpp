/*
 * @Author: FANG
 * @Date: 2021-09-16 12:25:11
 * @LastEditTime: 2021-09-16 12:25:11
 * @Description: Intersection of Two Arrays II
 * @FilePath: \DSA\QuestionSet\Leetcode\350. Intersection of Two Arrays II.cpp
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1, p2;
        p1 = p2 = 0;
        vector<int> ans;
        while (p1 < nums1.size() and p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) p1++;
            else if (nums1[p1] > nums2[p2]) p2++;
            else if (nums2[p2] == nums1[p1]) {
                ans.push_back(nums2[p2]);
                p1++, p2++;
            }
        }
        return ans;
    }
};