class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto vec:times){
            int u=vec[0],v=vec[1], w=vec[2];
            adj[u].push_back({w,v});
        }
        vector<int>distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
                distance[k]=0;
        while(!pq.empty()){
            auto [d, u]=pq.top();
            pq.pop();
            if(distance[u]<d)continue;
            for(auto [wt, v]:adj[u]){
                if(distance[v]>distance[u]+wt){
                    distance[v]=distance[u]+wt;
                    pq.push({distance[v], v});
                }
            }
        }

        int value=*max_element(distance.begin()+1, distance.end());
        return (value!=INT_MAX)?value:-1;
    }
};