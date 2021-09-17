/*
 * @Author: FANG
 * @Date: 2021-09-07 21:55:00
 * @LastEditTime: 2021-09-07 21:55:00
 * @Description: Single Number
 * @FilePath: \DSA\QuestionSet\Leetcode\136. Single Number.cpp
 */
// map<int, int>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] += 1;
        }
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) return it->first;
        }
        return 1;
    }
};