class Solution {
public:
    int dp[5001][1002];
    int f(vector<int>& prices, int index,int prev){
        if(index>=prices.size())return 0;
        if(dp[index][prev]!=-1)return dp[index][prev];
        int ans=f(prices, index+1, prev);
        if(prev==1001){
            ans=max(ans, f(prices, index+1, prices[index]));
        }else{
            ans=max(ans, f(prices, index+2, 1001)+prices[index]-prev);
        }
        return dp[index][prev]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(prices, 0, 1001);
    }
};