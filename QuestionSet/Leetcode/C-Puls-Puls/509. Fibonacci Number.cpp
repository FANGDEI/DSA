/*
 * @Author: FANG
 * @Date: 2021-09-06 20:38:12
 * @LastEditTime: 2021-09-06 20:38:12
 * @Description: Fibonacci Number
 * @FilePath: \DSA\QuestionSet\Leetcode\509. Fibonacci Number.cpp
 */
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int tmp, a = 0, b = 1;
        for (int i=2; i<=n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return tmp;
    }
};
/*
*/