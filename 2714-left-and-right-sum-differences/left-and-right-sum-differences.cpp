class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;
        int left=0;int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            sum-=nums[i];
            res[i]=abs(sum-left);
            left+=nums[i];
        }
        return res;
    }
};