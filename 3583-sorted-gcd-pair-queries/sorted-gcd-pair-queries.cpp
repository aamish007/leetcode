class Solution {
public:
    int bs(vector<long long>& a, long long x){
        int l=0, h=a.size()-1;
        int res=-1;
        while(h>=l){
            int mid=(h+l)/2;
            if(a[mid]>=x){
                h=mid-1;
                res=mid;
            }else if(a[mid]<x){
                l=mid+1;
            }
        }
        return res;
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int>res;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<long long>helper(maxi+1,0);
        for(int i:nums)helper[i]++;
        for(int i=1;i<=maxi;i++){
            for(int j=2*i;j<=maxi;j+=i){
                helper[i]+=helper[j];
            }
        }
        for(int i=1;i<=maxi;i++){
            helper[i]=helper[i]*(helper[i]-1)/2;
        }
        for(int i=maxi;i>=1;i--){
            for(int j=2*i;j<=maxi;j+=i){
                helper[i]-=helper[j];
            }
        }
        for(int i=1;i<=maxi;i++){
            helper[i]+=helper[i-1];
        }
        for(auto q:queries){
            int index=bs(helper, q+1);
            res.push_back(index);
        }
        return res;
    }
};