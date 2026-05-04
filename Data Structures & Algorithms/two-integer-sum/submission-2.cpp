class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int, int> indices;
        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            if (indices.contains(need)) {
                return {indices[need], i};
            }
            indices[nums[i]] = i;
        }

        return {};
    }
};
