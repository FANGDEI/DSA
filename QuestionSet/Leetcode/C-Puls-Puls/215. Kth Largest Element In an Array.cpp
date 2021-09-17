/*
 * @Author: FANG
 * @Date: 2021-09-06 19:49:53
 * @LastEditTime: 2021-09-06 19:52:50
 * @Description: Kth Largest Element in an Array
 * @FilePath: \DSA\QuestionSet\Leetcode\215.Kth Largest Element In an Array.cpp
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        find(nums, 0, nums.size() - 1, k);
        return nums[nums.size() - k];
    }
private:
    /**
     * @Author: FANG
     * @description: 将数组中最大的前k个元素放在数组的最右边
     * @param {int} s 起始
     * @param {int} e 结束
     * @param {int} k 要查找第几大的元素
     * @return {*}
     */    
    void find(vector<int>& a, int s, int e, int k) {
        if (s >= e) return ;
        int val = a[s];
        int i = s, j = e;
        while (i != j) {
            while (i < j and a[j] >= val) --j;
            swap(a[i], a[j]);
            while (i < j and a[i] <= val) ++i;
            swap(a[i], a[j]);
        }
        if (e - i + 1 == k) return ;
        else if (e - i + 1 > k) find(a, i + 1, e, k);
        else if (e - i + 1 < k) find(a, s, i - 1, k - (e - i + 1));
    }
};