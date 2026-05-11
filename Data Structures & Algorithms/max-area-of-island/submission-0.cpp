class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int dy[] {-1, 0, 1, 0};
        int dx[] {0, -1, 0, 1};
        function<int(int, int)> dfs = [&](int y, int x) {
            if (y == -1 || y == r || x == -1 || x == c) return 0;
            if (!grid[y][x]) return 0;
            grid[y][x] = 0;
            
            int result = 1;
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                result += dfs(ny, nx);
            }
            return result;
        };

        int result = 0;
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                result = max(result, dfs(y, x));
            }
        }
        return result;
    }
};
