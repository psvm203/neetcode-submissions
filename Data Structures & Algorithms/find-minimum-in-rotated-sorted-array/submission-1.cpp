class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (nums[md] >= nums[0]) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }
        
        int result = lo == n ? nums[0] : nums[lo];
        return result;
    }
};
