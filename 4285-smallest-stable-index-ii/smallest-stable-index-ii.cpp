class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();vector<int>mini(n);int p=INT_MAX;
        for(int i=n-1;i>=0;i--){
            p=min(nums[i],p);
            mini[i]=p;
        }
        int res=-1;int q=INT_MIN;
        for(int i=0;i<n;i++){
            q=max(nums[i],q);
            int score=q-mini[i];
            if(score<=k)return i;
        }
        return -1;
    }
};