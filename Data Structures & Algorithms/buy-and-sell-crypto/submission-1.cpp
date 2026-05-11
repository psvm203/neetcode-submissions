class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minPrice = 1e9;
        
        for (int price : prices) {
            result = max(result, price - minPrice);
            minPrice = min(minPrice, price);
        }

        return result;
    }
};
