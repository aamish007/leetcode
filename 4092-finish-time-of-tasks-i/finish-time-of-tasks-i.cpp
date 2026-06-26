class Solution {
public:
    vector<long long>vecna;
    void dfs(int i, vector<vector<int>> &adj,vector<int>& baseTime){
        if(adj[i].size()==0)return;
        long long earliest=LLONG_MAX, latest=LLONG_MIN;
        for(int j:adj[i]){
            if(vecna[j]==0)dfs(j, adj,baseTime);
            earliest=min(earliest, vecna[j]);
            latest=max(latest, vecna[j]);
        }
        vecna[i]=latest-earliest;
        vecna[i]+=baseTime[i];
        vecna[i]+=latest;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        vecna.resize(n);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==0)vecna[i]=baseTime[i];
        }
        if(vecna[0])return vecna[0];
        for(int i=0;i<n;i++){
            if(vecna[i])continue;
            if(vecna[0])return vecna[0];
            dfs(i, adj, baseTime);
        }
        return vecna[0];
    }
};