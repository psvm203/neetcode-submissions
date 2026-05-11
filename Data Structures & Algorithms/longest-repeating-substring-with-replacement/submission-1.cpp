class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lo = 0;
        int hi = 0;
        int result = 0;
        int totalCounts = 0;
        map<char, int> counts;
        map<int, set<char>> chars;

        while (hi < n) {
            hi++;
            totalCounts++;
            chars[counts[s[hi - 1]]].erase(s[hi - 1]);
            if (chars[counts[s[hi - 1]]].empty()) chars.erase(counts[s[hi - 1]]);
            counts[s[hi - 1]]++;
            chars[counts[s[hi - 1]]].emplace(s[hi - 1]);
            while (chars.size() && (totalCounts - chars.rbegin()->first > k)) {
                totalCounts--;
                chars[counts[s[lo]]].erase(s[lo]);
                if (chars[counts[s[lo]]].empty()) chars.erase(counts[s[lo]]);
                counts[s[lo]]--;
                chars[counts[s[lo]]].emplace(s[lo]);
                lo++;
            }
            result = max(result, hi - lo);
        }

        return result;
    }
};
