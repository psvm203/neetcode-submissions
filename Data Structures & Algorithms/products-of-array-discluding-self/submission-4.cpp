class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector prefixProduct{1};
        for (int num : nums) {
            prefixProduct.emplace_back(num * prefixProduct.back());
        }

        vector postfixProduct{1};
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            postfixProduct.emplace_back(*it * postfixProduct.back());
        }

        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.emplace_back(prefixProduct[i] * postfixProduct[n - i - 1]);
        }
        return result;
    }
};
