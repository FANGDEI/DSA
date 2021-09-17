/*
 * @Author: FANG
 * @Date: 2021-09-12 23:46:36
 * @LastEditTime: 2021-09-12 23:46:36
 * @Description: Count Primes
 * @FilePath: \DSA\QuestionSet\Leetcode\204. Count Primes.cpp
 */
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0, isPrime[5000005];
        memset(isPrime, 0, sizeof(isPrime));
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == 0) {
                ans++;
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = 1;
                }
            }
        }
        return ans;
    }
};
