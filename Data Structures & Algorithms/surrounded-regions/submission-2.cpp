class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int dy[] {-1, 0, 1, 0};
        int dx[] {0, -1, 0, 1};

        function<void(int, int)> dfs = [&](int y, int x) {
            if (y == -1 || y == r || x == -1 || x == c) return;
            if (board[y][x] != 'O') return;
            board[y][x] = '#';

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                dfs(ny, nx);
            }
        };

        for (int y = 0; y < r; y++) {
            dfs(y, 0);
            dfs(y, c - 1);
        }
        for (int x = 0; x < c; x++) {
            dfs(0, x);
            dfs(r - 1, x);
        }

        for (auto& row : board) {
            for (char& item : row) {
                if (item == 'O') item = 'X';
                if (item == '#') item = 'O';
            }
        }
    }
};
