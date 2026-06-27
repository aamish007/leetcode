class Solution {
public:
    int dp[10][2][2][11];
    int solve(int index, bool lead, bool tight, int seen, string &s){
        if(index==(int)s.size()){
            return seen;
        }
        if(dp[index][lead][tight][seen]!=-1 && !tight)return dp[index][lead][tight][seen];
        int upper=9;if(tight)upper=s[index]-'0';
        int ans=0;
        for(int i=0;i<=upper;i++){
            if(i==1){
                ans+=solve(index+1, lead && i==0, tight && i==upper, seen+1, s);
            }else{
                ans+=solve(index+1, lead && i==0, tight && i==upper, seen, s);
            }
        }
        if(!tight)dp[index][lead][tight][seen]=ans;
        return ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        return solve(0, true, true, 0, s);
    }
};