class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int n = r * c;

        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (matrix[md / c][md % c] < target) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }

        return lo < n && matrix[lo / c][lo % c] == target;
    }
};
