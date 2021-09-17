/*
 * @Author: FANG
 * @Date: 2021-09-10 14:35:38
 * @LastEditTime: 2021-09-10 14:35:38
 * @Description: Implement Strstr()
 * @FilePath: \DSA\QuestionSet\Leetcode\28. Implement Strstr().cpp
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                int j = i, k;
                for (k = 0; k < needle.size(); k++) {
                    if (needle[k] == haystack[j++]) continue;
                    else break;
                }
                if (k >= needle.size()) return i;
            }
        }
        return -1;
    }
};