class Solution {
public:
    typedef pair<int,pair<int,int>> ip;
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>distance(m, vector<int>(n, INT_MAX));
        priority_queue<ip,vector<ip>, greater<ip>>pq;
        pq.push({0, {0,0}});
        vector<vector<int>>dir={{0,1},{1,0}, {-1,0}, {0,-1}};
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int d=it.first,x=it.second.first,y=it.second.second;
            if(d>distance[x][y])continue;
            for(auto v:dir){
                int nx=x+v[0],ny=y+v[1];
                if(nx<0 || nx>=m || ny<0 || ny>=n)continue;
                if(distance[nx][ny]>d+grid[nx][ny]){
                    distance[nx][ny]=d+grid[nx][ny];
                    pq.push({distance[nx][ny], {nx, ny}});
                }
            }
        }
        return distance[m-1][n-1];
    }
};