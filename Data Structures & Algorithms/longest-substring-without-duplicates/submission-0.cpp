class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int lo = 0;
        int hi = 0;
        int result = 0;
        set<char> chars;

        while (hi < n) {
            hi++;
            while (chars.contains(s[hi - 1])) {
                chars.erase(s[lo++]);
            }
            chars.emplace(s[hi - 1]);
            result = max(result, hi - lo);
        }

        return result;
    }
};
