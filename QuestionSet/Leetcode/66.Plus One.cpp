/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-05 18:04:39
 * @Description: Plus One
 * @FilePath: /DSA/QuestionSet/Leetcode/66.Plus One.cpp
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& n) {
        int carry = 1; // 进位
        for (int i = n.size() - 1; i >= 0; i--) {
            int x = n[i] + carry;
            n[i] = x % 10;
            carry = x / 10;
            if (carry == 0) break;
        }
        if (carry != 0) n.insert(n.begin(), carry); // 循环结束 carry != 0 首位进一
        return n;
    }
};