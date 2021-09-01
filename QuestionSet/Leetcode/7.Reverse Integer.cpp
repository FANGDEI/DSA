/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-08-31 12:18:00
 * @LastEditTime: 2021-08-31 12:18:47
 * @Description: Reverse Integer
 * @FilePath: /Leetcode/7.Reverse Integer.cpp
 */
class Solution {
public:
    int reverse(int x) {
        long long tmp = 0;
        while (x) {
            tmp *= 10;
            tmp += x % 10;
            x /= 10;
        }
        if (tmp > pow(2, 31) - 1 || tmp < -pow(2, 31)) return 0;
        else return tmp;
    }
};