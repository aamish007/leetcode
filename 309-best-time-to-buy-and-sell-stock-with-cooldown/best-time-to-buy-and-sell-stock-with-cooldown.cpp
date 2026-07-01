class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> dp(n + 2, vector<long long> (2, 0));
        for(int i = n - 1; i > -1; i--)
        {
            dp[i][1] = max(-1 * prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
        }
        return dp[0][1];
    }
};