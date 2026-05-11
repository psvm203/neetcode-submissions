class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lo = 0;
        int hi = 0;
        int maxCount = 0;
        int result = 0;
        map<char, int> counts;

        while (hi < n) {
            maxCount = max(maxCount, ++counts[s[hi++]]);
            while (hi - lo - maxCount > k) {
                counts[s[lo++]]--;
            }
            result = max(result, hi - lo);
        }

        return result;
    }
};
