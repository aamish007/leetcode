class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];vector<int>prefixGcd(n);
        for(int i=0;i<n;i++){
            mx=max(nums[i],mx);
            prefixGcd[i]=gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int low=0, high=n-1;
        long long int ans=0;
        while(high>low){
            ans+=gcd(prefixGcd[low], prefixGcd[high]);
            low++;high--;
        }
        return ans;
    }
};