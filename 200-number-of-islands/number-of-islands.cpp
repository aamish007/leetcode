class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size(),n=grid[0].size();
       vector<vector<bool>>visited(m, vector<bool>(n,false));int islands=0;
       vector<vector<int>>dir={{1,0},{0,1}, {-1,0} , {0,-1}};
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='0' || visited[i][j])continue;
            queue<pair<int,int>>q;
            q.push({i,j});islands++;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(auto v:dir){
                    int nx=x+v[0],ny=y+v[1];
                    if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]=='0' || visited[nx][ny])continue;
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
       }
       return islands;
    }
};