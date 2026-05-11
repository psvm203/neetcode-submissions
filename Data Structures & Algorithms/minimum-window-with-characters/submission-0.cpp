class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = s.size();

        set<char> comp(t.begin(), t.end());
        int need = comp.size();

        map<char, int> counts;
        for (char ch : t) counts[ch]++;

        int lo = 0;
        int hi = 0;
        string result;

        while (hi < m) {
            char ch = s[hi];
            if (comp.contains(ch) && --counts[ch] == 0) {
                need--;
            }
            hi++;

            while (lo < hi && need == 0) {
                if (result.empty() || hi - lo < result.size()) {
                    result = s.substr(lo, hi - lo);
                }
                char ch = s[lo];
                if (comp.contains(ch) && counts[ch]++ == 0) {
                    need++;
                }
                lo++;
            }
        }

        return result;
    }
};
