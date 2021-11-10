/*
 * @Author: FANG
 * @Date: 2021-11-10 13:01:09
 */
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int endTime = 0, res = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] > endTime) {
                res += duration;
            } else {
                res += timeSeries[i] + duration - endTime;
            }
            endTime = timeSeries[i] + duration;
        }
        return res;
    }
};