/*
 * @Author: FANG
 * @Date: 2021-09-06 20:39:01
 * @LastEditTime: 2021-09-06 20:40:07
 * @Description: Binary Search
 * @FilePath: \DSA\QuestionSet\Leetcode\704. Binary Search.cpp
 */
class Solution {
public:
    int search(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (a[m] == t) return m;
            else if (a[m] > t) r = m - 1;
            else if (a[m] < t) l = m + 1;
        }
        return -1;
    }
};