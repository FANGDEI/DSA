/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-08-31 21:56:13
 * @LastEditTime: 2021-08-31 21:56:13
 * @Description: Palindrome Number
 * @FilePath: /Leetcode/9.Palindrome Number.cpp
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long tmp = x, _ = 0;
        while (tmp) {
            _ *= 10;
            _ += tmp % 10;
            tmp /= 10;
        }
        if (x == _) return true;
        else return false;
    }
};