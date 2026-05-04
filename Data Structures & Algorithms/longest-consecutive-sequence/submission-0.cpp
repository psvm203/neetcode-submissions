class Solution {
public:
    unordered_set<int> exists;
    unordered_map<int, int> memo;

    int dfs(int x) {
        if (memo.contains(x)) return memo[x];
        int& m = memo[x];
        if (!exists.contains(x)) return m = 0;
        return m = 1 + dfs(x - 1);
    }

    int longestConsecutive(vector<int>& nums) {
        for (int num : nums) {
            exists.emplace(num);
        }

        int result = 0;
        for (int num : nums) {
            result = max(result, dfs(num));
        }
        return result;
    }
};
