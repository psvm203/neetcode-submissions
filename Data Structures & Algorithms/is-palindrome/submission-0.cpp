class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;

        while (lo < hi) {
            if (!isalnum(s[lo])) {
                lo++;
                continue;
            }
            if (!isalnum(s[hi])) {
                hi--;
                continue;
            }
            if (tolower(s[lo++]) != tolower(s[hi--])) return false;
        }

        return true;
    }
};
