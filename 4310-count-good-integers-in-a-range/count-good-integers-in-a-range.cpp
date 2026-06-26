class Solution {
public:
    int lim;
    long long dp[16][2][2][11]; // prev shifted by +1, so range is 0..10 (representing -1..9)

    long long solve(string &s, int index, bool tight, bool lead, int prev){
        if(index == (int)s.size()) return 1;
        
        if(!tight && dp[index][tight][lead][prev+1] != -1) 
            return dp[index][tight][lead][prev+1];
        
        int upper = 9;
        if(tight) upper = s[index]-'0';
        
        long long ans = 0;
        for(int i = 0; i <= upper; i++){
            if(prev != -1 && abs(i - prev) > lim) continue;
            
            bool newLead = lead && (i == 0);
            int newPrev = newLead ? -1 : i;
            
            ans += solve(s, index+1, tight && (i == upper), newLead, newPrev);
        }
        
        if(!tight) dp[index][tight][lead][prev+1] = ans;
        return ans;
    }
    
    long long countGood(string s){
        if(s == "0") return 1; // only "0" itself, handled as base case below works too
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, true, true, -1);
    }

    long long goodIntegers(long long l, long long r, int k) {
        lim = k;
        long long high = countGood(to_string(r));
        long long low = (l - 1 >= 0) ? countGood(to_string(l - 1)) : 0;
        return high - low;
    }
};