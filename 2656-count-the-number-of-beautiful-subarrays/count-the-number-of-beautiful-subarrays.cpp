class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res=0;int bits=0;
        unordered_map<int,long long>freq;
        freq[bits]++;
        for(int i:nums){
            bits^=i;
            res+=freq[bits];
            freq[bits]++;
        }
        return res;
    }
};