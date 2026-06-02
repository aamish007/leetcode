class Solution {
public:
    int dp[1001][1501];
    vector<int>free;
    int n,small;
    int solve(int i, int total, vector<vector<int>>& items){
        if(i>=items.size())return total/small;
        if(dp[i][total]!=-1)return dp[i][total];
        int take=INT_MIN;
        if(items[i][1]<=total){
            take=free[i]+solve(i+1, total-items[i][1], items);
        }
        int skip=solve(i+1, total, items);
        return dp[i][total]=max(skip, take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();small=INT_MAX;free.resize(n,0);
        for(int i=0;i<n;i++){
            small=min(small, items[i][1]);
            for(int j=0;j<n;j++){
                if(items[j][0]%items[i][0]==0)free[i]++;
            }
        }
        memset(dp,-1, sizeof(dp));
        return solve(0, budget, items);
    }
};