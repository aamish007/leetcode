class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=0;int n=words.size();
        while(ans<n){
            int next=(startIndex+ans)%n;
            int prev=(startIndex-ans+n)%n;
            if(words[prev]==target || words[next]==target)return ans;
            ans++;
        }
        return -1;
    }
};