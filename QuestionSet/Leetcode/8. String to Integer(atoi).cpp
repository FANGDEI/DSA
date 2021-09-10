/*
 * @Author: FANG
 * @Date: 2021-09-10 14:25:42
 * @LastEditTime: 2021-09-10 14:26:18
 * @Description: String to Integer(atoi)
 * @FilePath: \DSA\QuestionSet\Leetcode\8. String to Integer(atoi).cpp
 */
class Solution {
public:
    int myAtoi(string s) {
        // for (int i = 0; i < s.length(); i++) if (s[i] == '+') s[i] = '0';
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        long long flag = 1;
        if (s[i] == '-') {flag = -1, i++; goto La;}
        if (s[i] == '+') i++;
        La:if (s[i] < '0' and s[i] > '9') return 0;
        string t = "";
        while (s[i] >= '0' and s[i] <= '9') t += s[i++];
        long long res = 0;
        for (int j = 0; j < t.length(); j++) {
            if (res >= pow(2, 31) - 1) goto Lb;
            res *= 10;
            res += t[j] - '0';
        }
        Lb:
        res *= flag;
        if (res > pow(2, 31) - 1) res = pow(2, 31) - 1;
        if (res < -pow(2, 31)) res = -2147483648;
        return res;
    }
};