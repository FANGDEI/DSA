/*
 * @Author: FANG
 * @Date: 2021-09-06 20:29:03
 * @LastEditTime: 2021-09-06 20:29:04
 * @Description: Sort Color
 * @FilePath: \DSA\QuestionSet\Leetcode\75.Sort Color.cpp
 */
class Solution {
public:
    void quickSort(vector<int>& a, int s, int e) {
        if (s >= e) return ;
        int k = a[s];
        int i = s, j = e;
        while (i != j) {
            while (j > i and a[j] >= k) j--;
            swap(a[i], a[j]);
            while (i < j and a[i] <= k) i++;
            swap(a[i], a[j]);
        }
        quickSort(a, s, i - 1);
        quickSort(a, i + 1, e);
    }
                                        
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};