/*
 * @Author: FANG
 * @Date: 2021-09-07 21:46:46
 * @LastEditTime: 2021-09-07 21:46:47
 * @Description: Best Time to Buy and Sell Stock
 * @FilePath: \DSA\QuestionSet\Leetcode\121. Best Time To Buy and Sell Stock.cpp
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrices);
            if (minPrices > prices[i]) minPrices = prices[i];
        }
        return profit;
    }
};

/*
    // TLE
    int maxProfit(vector<int>& prices) {
        int f[100005];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                int profit = prices[i] - prices[j];
                f[i] = max(f[i], profit);
            }
        }
        int ans = -0x3f3f3f3f;
        for (int i = 0; i < prices.size(); i++) ans = max(ans, f[i]);
        return ans > 0 ? ans : 0;
    }
*/