class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n, INT_MAX);dist[k-1]=0;
        for(int i=0;i<n-1;i++){
            for(auto v:times){
                int u=v[0]-1, node=v[1]-1, wt=v[2];
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[node])
                dist[node]=dist[u]+wt;
            }
        }
        int mini=*max_element(dist.begin(), dist.end());
        return mini!=INT_MAX?mini:-1;
    }
};