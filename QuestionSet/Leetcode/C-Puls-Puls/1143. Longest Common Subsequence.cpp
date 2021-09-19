/*
 * @Author: FANG
 * @Date: 2021-09-19 21:44:34
 * @LastEditTime: 2021-09-19 21:44:35
 * @Description: Longest Common Subsequence
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\1143. Longest Common Subsequence.cpp
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int f[1005][1005];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= text1.length(); i++) {
            for(int j = 1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[text1.length()][text2.length()];
    }
};