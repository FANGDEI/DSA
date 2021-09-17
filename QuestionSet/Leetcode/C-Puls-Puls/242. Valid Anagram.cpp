/*
 * @Author: FANG
 * @Date: 2021-09-09 13:33:39
 * @LastEditTime: 2021-09-09 13:33:39
 * @Description: Valid Anagram
 * @FilePath: \DSA\QuestionSet\Leetcode\242. Valid Anagram.cpp
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())  return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};