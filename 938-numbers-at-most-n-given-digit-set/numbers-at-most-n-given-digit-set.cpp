class Solution {
public:
    vector<bool> digit;
    int dp[11][2];
    int solve(string& s, int pos, bool tight, bool lead) {
        if (pos == s.size())
            return !lead;

        if (!tight && dp[pos][lead] != -1)
            return dp[pos][lead];

        int lim = tight ? s[pos] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= lim; d++) {

            if (!(lead && d == 0) && !digit[d])
                continue;

            ans += solve(s, pos + 1, tight && (d == lim), lead && (d == 0));
        }

        if (!tight)
            dp[pos][lead] = ans;

        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        digit.resize(10);
        for (auto s : digits) {
            digit[s[0] - '0'] = true;
        }
        memset(dp, -1, sizeof(dp));
        string s=to_string(n);
        return solve(s,0, true,true);
    }
};