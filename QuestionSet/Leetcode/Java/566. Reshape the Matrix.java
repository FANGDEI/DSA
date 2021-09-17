/*
 * @Author: FANG
 * @Date: 2021-09-17 16:54:44
 * @LastEditTime: 2021-09-17 16:54:44
 * @Description: Reshape the Matrix
 * @FilePath: \DSA\QuestionSet\Leetcode\Java\566. Reshape the Matrix.java
 */
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        if (r * c != mat.length * mat[0].length) return mat;
        int rowVal = 0, colVal = 0;
        // int newRowVal = 0, newColVal = 0;
        int[][] newMat = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                newMat[i][j] = mat[rowVal][colVal];
                colVal++;
                if (colVal % mat[0].length == 0) {
                    rowVal++;
                    colVal = 0;
                }
            }
        }
        return newMat;
    }
}