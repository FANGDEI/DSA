/*
 * @Author: FANG
 * @Date: 2021-09-09 13:28:19
 * @LastEditTime: 2021-09-09 13:28:19
 * @Description: Reverse String
 * @FilePath: \DSA\QuestionSet\Leetcode\344. Reverse String.cpp
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }
};