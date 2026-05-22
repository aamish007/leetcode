class Solution {
public:
    int minFlips(string s) {
        int n=s.size();int ones=0;
        for(char ch:s){
            if(ch=='1')ones++;
        }
        int zeroes=n-ones;int ans=INT_MAX;
        if(zeroes==n)return 0;
        else ans=min(ans, ones);
        if(ones==n)return 0;
        else ans=min(ans, zeroes);
        if(ones==1)return 0;
        else ans=min(ans, max(0,ones-1));
        if(ones==2 && s[0]=='1' && s[n-1]=='1')return 0;
        else{
            int curr=0;
            for(int i=0;i<n;i++){
                if(s[0]!='1')curr++;
                if(s[n-1]!='1')curr++;
                if(i>0 && i<n-1 && s[i]=='1')curr++;
            }
            ans=min(ans, curr);
        }
        return ans;
    }
};