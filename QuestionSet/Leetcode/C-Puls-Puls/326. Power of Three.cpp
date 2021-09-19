/*
 * @Author: FANG
 * @Date: 2021-09-19 21:57:59
 * @LastEditTime: 2021-09-19 21:57:59
 * @Description: Power of Three
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\326. Power of Three.cpp
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return 1162261467 % n == 0;
    }
};