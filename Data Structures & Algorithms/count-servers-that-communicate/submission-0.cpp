class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int result = 0;

        for (auto& row : grid) {
            vector<int> servers;
            for (int x = 0; x < c; x++) {
                if (!row[x]) continue;
                servers.emplace_back(x);
            }
            if (servers.size() < 2) continue;
            for (int server : servers) {
                if (row[server] == 1) result++;
                row[server] = 2;
            }
        }

        for (int x = 0; x < c; x++) {
            vector<int> servers;
            for (int y = 0; y < r; y++) {
                if (!grid[y][x]) continue;
                servers.emplace_back(y);
            }
            if (servers.size() < 2) continue;
            for (int server : servers) {
                if (grid[server][x] == 1) result++;
                grid[server][x] = 2;
            }
        }

        return result;
    }
};