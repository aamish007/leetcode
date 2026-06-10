class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,-1}, {0,1}, {1,0}};
    void dfs(int r, int c, vector<vector<bool>>& reachable,vector<vector<int>>& heights){
        reachable[r][c]=true;
        for(auto v:dir){
            int nx=r+v[0],ny=c+v[1];
            if(nx>=0 && nx<heights.size() && ny>=0 && ny<heights[0].size() && !reachable[nx][ny] && heights[nx][ny]>=heights[r][c]){
                dfs(nx,ny, reachable, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n, false));
        vector<vector<bool>>atlantic(m,vector<bool>(n, false));
        for(int j=0;j<n;j++){
            dfs(0,j,pacific, heights);
            dfs(m-1,j, atlantic, heights);
        }
        for(int i=0;i<m;i++){
            dfs(i,0,pacific, heights);
            dfs(i,n-1, atlantic, heights);
        }
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};