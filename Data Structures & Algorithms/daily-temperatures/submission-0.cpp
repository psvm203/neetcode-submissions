class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> stk;
        vector result(n, 0);
        for (int i = 0; i < n; i++) {
            while (stk.size() && stk.back().first < nums[i]) {
                int j = stk.back().second;
                result[j] = i - j;
                stk.pop_back();
            }
            stk.emplace_back(nums[i], i);
        }
        return result;
    }
};
