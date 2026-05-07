class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        ranges::sort(nums);
        map<int, int> indices;
        for (int i = 0; i < n; i++) {
            indices[nums[i]] = i;
        }

        set<vector<int>> s;
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                int target = - nums[i] - nums[j];
                if (indices[target] > j) {
                    vector v{nums[i], nums[j], target};
                    s.emplace(v);
                }
            }
        }

        vector result(s.begin(), s.end());
        return result;
    }
};
