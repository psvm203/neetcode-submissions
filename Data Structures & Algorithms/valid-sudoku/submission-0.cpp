class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            vector<int> visited(9);
            for (char ch : board[r]) {
                if (ch == '.') continue;
                int num = ch - '1';
                if (visited[num]) return false;
                visited[num] = true;
            }
        }

        for (int c = 0; c < 9; c++) {
            vector<int> visited(9);
            for (int r = 0; r < 9; r++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                int num = ch - '1';
                if (visited[num]) return false;
                visited[num] = true;
            }
        }

        for (int y = 0; y < 9; y += 3) {
            for (int x = 0; x < 9; x += 3) {
                vector<int> visited(9);
                for (int r = y; r < y + 3; r++) {
                    for (int c = x; c < x + 3; c++) {
                        char ch = board[r][c];
                        if (ch == '.') continue;
                        int num = ch - '1';
                        if (visited[num]) return false;
                        visited[num] = true;
                    }
                }
            }
        }

        return true;
    }
};
