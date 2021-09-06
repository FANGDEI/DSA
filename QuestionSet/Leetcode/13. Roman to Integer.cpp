/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-01 13:55:49
 * @LastEditTime: 2021-09-01 14:09:43
 * @Description: Roman to Integer
 * @FilePath: /Leetcode/13.Roman to Integer.cpp
 */
// #include <map>
// #include <string>
// std::map<std::string, int> m;
// m["I"] = 1;
// std::map<char, int> m;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                     {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = 0;
        for (int i=0; i<s.length() -1; i++) {
            if (m[s[i]] < m[s[i+1]]) sum -= m[s[i]];
            else sum += m[s[i]];
        }
        sum += m[s[s.length()-1]];
        return sum;
    }
};