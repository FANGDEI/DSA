/*
 * @Author: FANG
 * @Date: 2022-01-01 15:27:47
 */
class Solution {
    public int mostWordsFound(String[] sentences) {
        int res = -0x3f3f;
        for (int i = 0; i < sentences.length; i++) {
            if (sentences[i].split(" ").length > res)
                 res = sentences[i].split(" ").length;
        }
        return res;
    }
}