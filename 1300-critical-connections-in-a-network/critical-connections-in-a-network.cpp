class Solution {
    int timer=1;
public:
    vector<vector<int>>res;
    void dfs(int node, int parent, vector<int>&low, vector<int>&t, vector<bool>&visit,   vector<vector<int>>&graph){
        low[node]=t[node]=timer;
        timer++;
        for(int i:graph[node]){
            if(i==parent)continue;
            if(!visit[i]){
                visit[i]=true;
                dfs(i, node, low, t, visit, graph);
                low[node]=min(low[node], low[i]);
                if(low[i]>t[node]){
                    res.push_back({node, i});
                }
            }
            else{
                low[node]=min(low[node], low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>low(n,0), t(n,0);
        vector<vector<int>>graph(n);
        for(auto v:connections){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool>visit(n,false);visit[0]=true;
        dfs(0,-1, low, t, visit, graph);
        return res;
    }
};