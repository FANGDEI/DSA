/*
 * @Author: FANG
 * @Date: 2021-12-27 00:12:35
 */
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSort(nums, 0, nums.length - 1, k);
    }
    int quickSort(int[] nums, int s, int e, int kth) {
        int k = nums[s];
        int i = s, j = e;
        while (i != j) {
            while (i < j && nums[j] <= k) j--;
            swap(nums, i, j);
            while (i < j && nums[i] >= k) i++;
            swap(nums, i, j);
        }
        if (i == kth - 1) return nums[i];
        if (i < kth - 1) return quickSort(nums, i + 1, e, kth);
        else return quickSort(nums, s, i - 1, kth);
    }
    void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}