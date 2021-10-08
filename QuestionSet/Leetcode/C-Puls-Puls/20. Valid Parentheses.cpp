/*
 * @Author: FANG
 * @Date: 2021-10-08 13:26:10
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            } else if (s[i] == ')') {
                if (sta.empty()) return false;
                if (sta.top() != '(') return false;
                sta.pop();
            }
            else if (s[i] == ']') {
                if (sta.empty()) return false;
                if (sta.top() != '[') return false;
                sta.pop();
            }
            else if (s[i] == '}') {
                if (sta.empty()) return false;
                if (sta.top() != '{') return false;
                sta.pop();
            }
        }
        if (sta.empty()) return true;
        return false;
    }
};