class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();vector<long long> res(n);
        unordered_map<int,int>prev, next;
        unordered_map<int, long long>prevSum,nextSum;
        for(int i=n-1;i>0;i--){
            next[nums[i]]++;
            nextSum[nums[i]]+=i;
        }
        for(int i=0;i<n;i++){
            if(next.find(nums[i])!=next.end() && next[nums[i]]>0){
                res[i]+=nextSum[nums[i]]-(1LL*next[nums[i]]*i);
            }
            if(prev.find(nums[i])!=prev.end() && prev[nums[i]]>0){
                res[i]+=(1LL*prev[nums[i]]*i)-prevSum[nums[i]];
            }
            if(i<n-1){
                next[nums[i+1]]--;
                nextSum[nums[i+1]]-=(i+1);
            }
            prev[nums[i]]++;
            prevSum[nums[i]]+=i;
        }
        return res;
    }
};