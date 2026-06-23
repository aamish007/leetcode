class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<vector<long long>,vector<vector<long long>>, greater<vector<long long>>>pq;
        vector<vector<long long>>dist(n, vector<long long>(k+1,LLONG_MAX));
        vector<vector<pair<int,int>>>adj(n);
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        dist[0][k]=0;
        pq.push({0,0,k});
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int d=i[0], u=i[1], rem=i[2];
            if(d>dist[u][rem])continue;
            for(auto& it:adj[u]){
                int v=it.first,w=it.second;
                if(labels[v]==labels[u]){
                    if(rem<=1)continue;
                    int nrem=rem-1;
                    if(dist[v][nrem]>d+w){
                        dist[v][nrem]=d+w;
                        pq.push({dist[v][nrem], v, nrem});
                    }
                } else{
                    if(dist[v][k]>d+w){
                        dist[v][k]=d+w;
                        pq.push({dist[v][k],v,k});
                    }
                }
            }
        }
        long long ans=LLONG_MAX;
        for(int i=1;i<=k;i++){
            if(dist[n-1][i]<ans)ans=dist[n-1][i];
        }
        return ans==LONG_MAX?-1:(int)ans;
    }
};