/*
 * @Author: FANG
 * @Date: 2021-09-13 15:35:00
 * @LastEditTime: 2021-09-13 15:35:01
 * @Description: Unique Paths
 * @FilePath: \DSA\QuestionSet\Leetcode\62. Unique Paths.cpp
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[105][105];
        memset(f, 0, sizeof(f));
        f[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m][n];
    }
};