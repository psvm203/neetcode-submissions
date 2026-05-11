class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;

        map<char, int> counts;
        for (char ch : s1) counts[ch]++;

        int lo = 0;
        int hi = m;
        for (int i = lo; i < hi; i++) {
            char ch = s2[i];
            if (--counts[ch] == 0) counts.erase(ch);
        }

        while (hi < n) {
            if (counts.empty()) return true;
            if (++counts[s2[lo]] == 0) counts.erase(s2[lo]);
            lo++;
            if (--counts[s2[hi]] == 0) counts.erase(s2[hi]);
            hi++;
        }

        return counts.empty();
    }
};
