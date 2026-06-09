class Solution {
public:
    int m,n;
    bool safe(int i, int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;m=grid.size(),n=grid[0].size();
        int count=0;queue<pair<int,int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){q.push({i,j});visited[i][j]=true;}
                else if(grid[i][j]==1)count++;
            }
        }
        vector<vector<int>>dir={{1,0},{0,1},{-1, 0},{0, -1}};
        while(!q.empty() && count!=0){
            int s=q.size();
            minutes++;
            for(int i=0;i<s;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto v:dir){
                    int nx=x+v[0],ny=y+v[1];
                    if(!safe(nx,ny))continue;
                    if(!visited[nx][ny] && grid[nx][ny]==1){
                        visited[nx][ny]=true;
                        count--;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return count>0?-1:minutes;
    }
};