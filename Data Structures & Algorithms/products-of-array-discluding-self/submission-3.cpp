class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zero = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (zero != -1) {
                    vector result(n, 0);
                    return result;
                }
                zero = i;
                continue;
            }
            product *= nums[i];
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result.emplace_back(product);
                continue;
            }
            if (zero == -1) {
                result.emplace_back(product / nums[i]);
                continue;
            }
            result.emplace_back(0);
        }
        return result;
    }
};
