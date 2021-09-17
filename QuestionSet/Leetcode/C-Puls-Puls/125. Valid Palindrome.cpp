/*
 * @Author: FANG
 * @Date: 2021-09-06 20:26:55
 * @LastEditTime: 2021-09-06 20:26:55
 * @Description: Valid Palindrome
 * @FilePath: \DSA\QuestionSet\Leetcode\125.Valid Palindrome.cpp
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        string t = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' and s[i] <= '9') t += s[i];
            if ((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z')) t += tolower(s[i]);
        }
        int i = 0, j = t.length() - 1;
        while (i < j) {
            if (t[i] == t[j]) i++, j--;
            else return false;
        }
        return true;
    }
};