class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        for(auto v:grid){
            for(auto y:v){
                nums.push_back(y);
            }
        }
        sort(nums.begin(),nums.end());int n=nums.size();
        int mid=nums[n/2];int op=0;int rem=nums[0]%x;
        for(int i:nums){
            if(i%x!=rem)return -1;
            else op+=abs(i-mid)/x;
        }
        return op;
    }
};