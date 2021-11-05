/*
 * @Author: FANG
 * @Date: 2021-11-05 12:57:23
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) res += n & 1, n >>= 1;
        return res;
    }
};