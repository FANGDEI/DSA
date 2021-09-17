/*
 * @Author: FANG
 * @Date: 2021-09-06 20:34:05
 * @LastEditTime: 2021-09-06 20:34:05
 * @Description: Two Sum II -Input array is sorted
 * @FilePath: \DSA\QuestionSet\Leetcode\167.Two Sum II - Input array is sorted.cpp
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        int sum = numbers[i] + numbers[j];
        while (sum != target) {
            if (sum > target) j--;
            if (sum < target) i++;
            sum = numbers[i] + numbers[j];
        }
        return {i + 1, j + 1};
    }
};