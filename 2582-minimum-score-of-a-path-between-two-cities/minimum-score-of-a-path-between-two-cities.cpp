class Solution {
    class DSU{
        public: 
        vector<int>parent, size;
        DSU(int n){
            parent.resize(n);size.assign(n,1);
            for(int i=0;i<n;i++)parent[i]=i;
        }
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
        }
        void unite(int a, int b){
            a=find(a);
            b=find(b);
            if(a==b)return;
            if(size[a]<size[b])swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    };
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU du(n+1);
        for(auto &v:roads){
            du.unite(v[0], v[1]);
        }
        int mini=INT_MAX;
        for(auto &v:roads){
            if(du.find(v[0])==du.find(1)){
                mini=min(mini, v[2]);
            }
        }
        return mini;
    }
};