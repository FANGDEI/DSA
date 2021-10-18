/*
 * @Author: FANG
 * @Date: 2021-10-18 13:02:46
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < matrix.size() / 2; i++) matrix[i].swap(matrix[n - 1 - i]);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};