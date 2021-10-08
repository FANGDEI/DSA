/*
 * @Author: FANG
 * @Date: 2021-10-07 23:17:22
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < magazine.length(); i++) {
            table[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if (table[ransomNote[i] - 'a'] == 0) return false;
            else table[ransomNote[i] - 'a']--;
        }
        return true;
    }
};