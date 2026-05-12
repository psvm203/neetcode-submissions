class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector memo(n + 1, 0);
        memo[0] = 0;
        memo[1] = 0;
        for (int i = 2; i <= n; i++) {
            memo[i] = min(memo[i - 2] + cost[i - 2], memo[i - 1] + cost[i - 1]);
        }
        return memo[n];
    }
};
