/*
 * @Author: FANG
 * @Date: 2021-10-13 22:21:38
 */
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        DFS(n, 0, 0, "");
        return res;
    }
    void DFS(int n, int left, int right, string str) {
        if (left == n && right == n) res.push_back(str);
        else {
            if (left < n) DFS(n, left + 1, right, str + "(");
            if (right < n && left > right) DFS(n, left, right + 1, str + ")");
        }
    }
};