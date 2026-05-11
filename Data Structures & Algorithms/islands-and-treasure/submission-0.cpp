class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dy[]{-1, 0, 1, 0};
        int dx[]{0, -1, 0, 1};

        function<void(int, int, int)> dfs = [&](int y, int x, int dist) {
            if (y == -1 || y == r || x == -1 || x == c) return;
            if (dist && dist >= grid[y][x]) return;
            grid[y][x] = dist;
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                dfs(ny, nx, dist + 1);
            }
        };

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (grid[y][x] == 0) dfs(y, x, 0);
            }
        }
    }
};
