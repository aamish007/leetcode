class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n=nums.size();int dp[(1<<n)+2];int sum=0;
        fill(dp, dp+(1<<n)+2, -1);
        for(int i:nums)sum+=i;
        if(sum%4!=0)return false;
        dp[0]=0;sum/=4;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==-1)continue;
            for(int i=0;i<n;i++){
                if(!(mask & (1<<i)) && dp[mask]+nums[i]<=sum){
                    dp[mask | (1<<i)]=(dp[mask]+nums[i])%sum;
                }
            }
        }
        return dp[(1<<n)-1]==0;
    }
};