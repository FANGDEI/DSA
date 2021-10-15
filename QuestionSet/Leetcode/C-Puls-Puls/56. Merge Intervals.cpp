/*
 * @Author: FANG
 * @Date: 2021-10-15 16:03:29
 */
class Solution {
public:
    bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    vector<vector<int>> res;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // for (int i = 0; i < intervals.size(); i++) {
        //     for (int j = 0; j < intervals[i].size(); i++) {
        //         cout << intervals[i][j] << " ";
        //     }
        //     cout << "$" << " ";
        // }
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (l > res.back()[1]) {
                res.push_back({l, r});
            } else {
                res.back()[1] = max(res.back()[1], r);
            }
        }
        return res;
    }
};