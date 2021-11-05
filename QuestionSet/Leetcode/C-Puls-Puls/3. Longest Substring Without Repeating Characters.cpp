/*
 * @Author: FANG
 * @Date: 2021-11-04 23:50:30
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int res = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            m[s[i]]++;
            while (j <= i && m[s[i]] > 1) {
                m[s[j++]]--;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};