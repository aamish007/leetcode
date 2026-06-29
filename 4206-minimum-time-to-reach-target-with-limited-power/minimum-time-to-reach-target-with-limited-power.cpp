class Solution {
public:
    using p=tuple<long long,int,int>;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<long long>>distance(n, vector<long long>(power+1, LLONG_MAX));
        vector<long long>res(2,LLONG_MAX);vector<vector<pair<int,int>>>adj(n);
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<p,vector<p>, greater<p>>pq;
        pq.push({0,source,power});distance[source][power]=0;
        while(!pq.empty()){
            auto [T, u, po]=pq.top();
            pq.pop();
            if(T>distance[u][po])continue;
            for(auto [v,time]: adj[u]){
                if(cost[u]>po)continue;
                int newP=po-cost[u];
                if(distance[v][newP]>T+time){
                    distance[v][newP]=T+time;
                    pq.push({T+time, v, newP});
                }
            }
        }
        for(int i=power;i>=0;i--){
            if(res[0]>distance[target][i]){
                res[0]=distance[target][i];
                res[1]=i;
            }
        }
        if(res[0]==LLONG_MAX){
            res[0]=res[1]=-1;
        }
        return res;
    }
};