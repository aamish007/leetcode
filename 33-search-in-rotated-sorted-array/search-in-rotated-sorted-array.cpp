class Solution {
public:
    int s(vector<int>& nums, int low, int high, int target){
        while(high>=low){
            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int pos(vector<int>& nums){
        int s=0,e=nums.size()-1;
        while(e>=s){
            int i=(e+s)/2;
            if(i+1<nums.size() && nums[i]>nums[i+1]){
                return i;
            }
            else if(nums[i]>=nums[0])s=i+1;
            else if(nums[i]<nums[0])e=i-1;
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int index=pos(nums);
        if(index==nums.size())return -1;
        int ls=s(nums, 0, index,target);
        int rs=s(nums, index+1, nums.size()-1, target);
        if(ls==-1 && rs==-1)return -1;
        else if(ls==-1)return rs;
        return ls;
    }
};