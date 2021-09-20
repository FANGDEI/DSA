/*
 * @Author: FANG
 * @Date: 2021-09-20 17:59:30
 * @LastEditTime: 2021-09-20 17:59:30
 * @Description: Longest Common Prefix
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\14. Longest Common Prefix.cpp
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j;
            for (j = 0; j < min(res.size(), strs[i].size()); j++) {
                if (res[j] != strs[i][j]) break;
            }
            res = res.substr(0, j);
            if (res.length() == 0) return "";
        }
        return res;
    }
};