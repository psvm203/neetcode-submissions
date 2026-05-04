class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(nums[i], i);
        }
        ranges::sort(v);

        int lo = 0;
        int hi = n - 1;
        int sum = v[lo].first + v[hi].first;
        while (sum != target) {
            if (sum < target) {
                lo++;
            } else {
                hi--;
            }
            sum = v[lo].first + v[hi].first;
        }

        vector result {v[lo].second, v[hi].second};
        ranges::sort(result);
        return result;
    }
};
