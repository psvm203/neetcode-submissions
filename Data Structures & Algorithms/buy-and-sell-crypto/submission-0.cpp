class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;

        int n = prices.size();
        for (int lo = 0; lo + 1 < n; lo++) {
            for (int hi = lo + 1; hi < n; hi++) {
                result = max(result, prices[hi] - prices[lo]);
            }
        }

        return result;
    }
};
