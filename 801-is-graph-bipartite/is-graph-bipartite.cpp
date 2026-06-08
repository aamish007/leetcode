class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int>ump;int n=graph.size()-1;
        vector<bool>visited(n, false);
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            visited[i]=true;
            queue<int>q;
            int color=-1;
            if(ump.find(i)!=ump.end()){
                color=ump[i];
            }
            else{
                color=0;
                ump[i]=color;
            }
            q.push(i);
            while(!q.empty()){
                int s=q.size();
                for(int i=0;i<s;i++){
                    int u=q.front();
                    q.pop();
                    for(int v:graph[u]){
                        if(!visited[v]){
                            visited[v]=true;
                            if(ump.find(v)!=ump.end()){
                                if(ump[u]==ump[v])return false;
                            }
                            else{
                                ump[v]=1-ump[u];
                            }
                            q.push(v);
                        }
                        else{
                            if(ump[u]==ump[v])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};