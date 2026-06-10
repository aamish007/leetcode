class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>> pq;

        pq.push({0,0,0});

        while(!pq.empty()){
            auto [d,i,j] = pq.top();
            pq.pop();

            if(i == m-1 && j == n-1) return d; // optimization

            if(d > dist[i][j]) continue;

            for(auto &v : dir){
                int nx = i + v[0], ny = j + v[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int effort = max(d, abs(heights[i][j] - heights[nx][ny]));

                    if(dist[nx][ny] > effort){
                        dist[nx][ny] = effort;
                        pq.push({effort, nx, ny});
                    }
                }
            }
        }
        return 0;
    }
};