class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>=nums[n-1]){
            int rot;
            for(int i=0;i<n-1;i++){
                rot=i;
                if(nums[i]>nums[i+1])break;
            }
            for(int i=rot+1;i<n-1;i++){
                if(nums[i]>nums[i+1])return false;
            }
            return true;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
};