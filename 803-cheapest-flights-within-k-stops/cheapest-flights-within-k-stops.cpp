class Solution {
public:
    using t=tuple<int,int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>distance(n, vector<int>(k+1, INT_MAX));
        distance[src][0]=0;
        priority_queue<t,vector<t>, greater<t>>pq;
        vector<vector<pair<int,int>>>graph(n);
        for(auto v:flights){
            graph[v[0]].push_back({v[1],v[2]});
        }
        for(auto [v,c]:graph[src]){
            pq.push({c,v,0});
            distance[v][0]=c;
        }
        while(!pq.empty()){
            auto [c,u,stop]=pq.top();
            pq.pop();
            if(distance[u][stop]<c)continue;
            for(auto [v,temp]:graph[u]){
                int newC=c+temp,newS=stop+1;
                if(newS>k)continue;
                if(distance[v][newS]>newC){
                    distance[v][newS]=newC;
                    pq.push({newC,v, newS});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k;i++){
            ans=min(ans,distance[dst][i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};