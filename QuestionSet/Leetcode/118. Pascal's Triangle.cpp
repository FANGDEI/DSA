/*
 * @Author: FANG
 * @Date: 2021-09-07 21:17:36
 * @LastEditTime: 2021-09-07 21:17:36
 * @Description: Pascal's Triangle
 * @FilePath: \DSA\QuestionSet\Leetcode\118. Pascal's Triangle.cpp
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v(numRows);
        for (int i = 0; i < numRows; i++) {
            v[i].resize(i + 1);
            v[i][0] = v[i][i] = 1;
            for (int j = 1; j < i; j++) {
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
            }
        }
        return v;
    }
};
/*
1
1   1
1   2   1
1   3   3   1
*/