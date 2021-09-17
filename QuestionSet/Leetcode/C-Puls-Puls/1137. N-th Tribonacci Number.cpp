/*
 * @Author: FANG
 * @Date: 2021-09-06 20:39:33
 * @LastEditTime: 2021-09-06 20:39:33
 * @Description: N-th Tribonacci Number
 * @FilePath: \DSA\QuestionSet\Leetcode\1137. N-th Tribonacci Number.cpp
 */
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        int a = 0, b = 1, c = 1;
        int ans = 0;
        for (int i=3; i<=n; i++) {
            ans = a + b + c;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};