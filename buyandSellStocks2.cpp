class Solution {
public:
    int solve(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp)
    {
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index]+solve(prices, index+1, 0, dp), solve(prices, index+1, 1, dp));
        }
        else
        {
            profit = max(prices[index]+solve(prices, index+1, 1, dp), solve(prices, index+1, 0, dp));
        }
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = 1;
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(prices, 0, buy, dp);
    }
};