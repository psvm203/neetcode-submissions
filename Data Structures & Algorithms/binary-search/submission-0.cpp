class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n;

        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (nums[md] < target) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }

        int result = lo < n && nums[lo] == target ? lo : -1;
        return result;
    }
};
