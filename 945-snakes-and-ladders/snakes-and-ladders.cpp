class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n * n + 1);
        int idx = 1;
        for (int r = n - 1; r >= 0; r--) {
            if ((n - 1 - r) % 2 == 0) {
                for (int c = 0; c < n; c++)
                    arr[idx++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--)
                    arr[idx++] = board[r][c];
            }
        }
        vector<bool> vis(n * n + 1, false);
        queue<pair<int,int>> q;
        q.push({1, 0});
        vis[1] = true;
        while (!q.empty()) {
            auto [u, dist] = q.front();
            q.pop();
            if (u == n * n)
                return dist;
            for (int dice = 1; dice <= 6 && u + dice <= n * n; dice++) {
                int v = u + dice;
                if (arr[v] != -1)
                    v = arr[v];
                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, dist + 1});
                }
            }
        }
        return -1;
    }
};