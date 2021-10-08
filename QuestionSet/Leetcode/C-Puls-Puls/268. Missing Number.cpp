/*
 * @Author: FANG
 * @Date: 2021-10-08 16:37:08
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool a[nums.size() + 1];
        memset(a, false, sizeof(a));
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]] = true;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            if (a[i] == false) return i;
        }
        return -1;
    }
};