/*
 * @Author: FANG
 * @Date: 2021-09-06 20:35:42
 * @LastEditTime: 2021-09-06 20:35:42
 * @Description: First Bad Version
 * @FilePath: \DSA\QuestionSet\Leetcode\278.First Bad Version.cpp
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// typedef long long ll;
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};