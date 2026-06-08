class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>res;
        vector<vector<int>>graph(n);
        vector<int>indegree(n, 0);
        for(auto v:prerequisites){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int u=q.front();q.pop();
                res.push_back(u);
                for(int v:graph[u]){
                    if(indegree[v]>0)indegree[v]--;
                    if(indegree[v]==0)q.push(v);
                }
            }
        }
        if(res.size()!=n)return {};
        return res;
    }
};