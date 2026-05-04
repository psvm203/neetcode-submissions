class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set s(nums.begin(), nums.end());
        return nums.size() != s.size();
    }
};