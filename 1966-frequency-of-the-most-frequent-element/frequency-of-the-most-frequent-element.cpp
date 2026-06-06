class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=0;int i=0;int n=nums.size();long long sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(1LL*(j-i+1)*nums[j]-sum>k)sum-=nums[i++];
            res=max(res, j-i+1);
        }
        return res;
    }
};