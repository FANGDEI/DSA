/*
 * @Author: FANG
 * @Date: 2021-09-19 22:04:40
 * @LastEditTime: 2021-09-19 22:04:40
 * @Description: First Unique Character in a String
 * @FilePath: \DSA\QuestionSet\Leetcode\C-Puls-Puls\387. First Unique Character in a String.cpp
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int table[26];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < s.length(); i++) {
            table[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) if (table[s[i] - 'a'] == 1) return i;
        return -1;
    }
};