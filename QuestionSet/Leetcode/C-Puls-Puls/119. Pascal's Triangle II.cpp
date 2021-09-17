/*
 * @Author: FANG
 * @Date: 2021-09-07 21:29:15
 * @LastEditTime: 2021-09-07 21:29:15
 * @Description: Pascal's Triangle II
 * @FilePath: \DSA\QuestionSet\Leetcode\119. Pascal's Triangle II.cpp
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > v(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; i++) {
            v[i].resize(i + 1);
            v[i][0] = v[i][i] = 1;
            for (int j = 1; j < i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v[rowIndex];
    }
};