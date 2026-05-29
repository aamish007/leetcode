class Solution {
public:
    int digit(int i){
        int ans=0;
        while(i>0){
            ans+=i%10;
            i/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int res=INT_MAX;
        for(int i:nums){
            res=min(res, digit(i));
        }
        return res;
    }
};