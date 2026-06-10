class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int x:nums2){
            pq.push({x+nums1[0],0});
        }
        while(k-- && !pq.empty()){
            auto [u,v] =pq.top();
            pq.pop();
            res.push_back({nums1[v],u-nums1[v]});
            if(v+1<nums1.size()){
                pq.push({u-nums1[v]+nums1[v+1], v+1});
            }
        }
        return res;
    }
};