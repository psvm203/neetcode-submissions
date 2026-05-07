class Solution {
public:
    int64_t eatingHour(vector<int>& piles, int speed) {
        int64_t result = 0;
        for (int pile : piles) {
            result += (pile + speed - 1) / speed;
        }
        return result;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9 + 1;

        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (eatingHour(piles, md) > h) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }

        return lo;
    }
};
