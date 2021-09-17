/*
 * @Author: FANG
 * @Date: 2021-09-06 23:17:40
 * @LastEditTime: 2021-09-06 23:17:40
 * @Description: Reverse Vowels of a String
 * @FilePath: \DSA\QuestionSet\Leetcode\345. Reverse Vowels of a String.cpp
 */
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j and !check(s[i])) i++;
            while (i < j and !check(s[j])) j--;
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
private:
    bool check(char v) {
        if (v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U' ||
            v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u'
        ) return true;
        return false;
    }
};