class Solution {
   public:
    bool isAnagram(string s, string t) {
        multiset set_s(s.begin(), s.end()), set_t(t.begin(), t.end());
        return set_s == set_t;
    }
};
