/*
 * @Author: FANG
 * @Date: 2021-10-30 23:43:52
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) res.push_back(it->first);
        }
        return res;
    }
};