/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-09-05 17:17:09
 * @Description: Remove Element
 * @FilePath: /DSA/QuestionSet/Leetcode/27.Remove Element.cpp
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow, fast;
        slow = fast = 0;
        for ( ; fast < nums.size(); fast++) {
            if (nums[fast] != val) nums[slow++] = nums[fast];
        }
        return slow;
    }
};