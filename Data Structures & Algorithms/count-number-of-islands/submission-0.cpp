class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dy[] {-1, 0, 1, 0};
        int dx[] {0, -1, 0, 1};
        
        function<int(int, int)> dfs = [&](int y, int x) {
            if (grid[y][x] == '0') return 0;
            grid[y][x] = '0';

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny == -1 || ny == r || nx == -1 || nx == c) continue;
                dfs(ny, nx);
            }

            return 1;
        };

        int result = 0;
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                result += dfs(y, x);
            }
        }
        return result;
    }
};
