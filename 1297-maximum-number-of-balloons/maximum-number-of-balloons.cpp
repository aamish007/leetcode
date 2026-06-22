class Solution {
public://balloon
    int maxNumberOfBalloons(string text) {
        int ans=0;
        vector<int>freq(26,0);
        for(char ch:text){
            freq[ch-'a']++;
        }
        ans=min(freq[11]/2, freq[14]/2);
        ans=min(freq[0],ans);ans=min(ans,freq[1]);
        ans=min(ans,freq[13]);
        return ans;
    }
};