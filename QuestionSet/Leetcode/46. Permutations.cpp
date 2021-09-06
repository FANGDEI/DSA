/*
 * @Author: FANG(Ubuntu)
 * @Date: 2021-08-31 21:25:47
 * @LastEditTime: 2021-08-31 21:25:47
 * @Description: Permutations
 * @FilePath: /Leetcode/46.Permutations.cpp
 */
class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &nums, vector<int> &res,bool vis[]) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return ;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                res.push_back(nums[i]);
                dfs(ans, nums, res, vis);
                vis[i] = false;
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        bool vis[7];
        vector<vector<int> > ans;
        vector<int> res;
        memset(vis, false, sizeof(vis));
        dfs(ans, nums, res, vis);
        return ans;
    }
};