class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> opposite {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        for (char ch : s) {
            if (opposite.contains(ch)) {
                stk.emplace(ch);
                continue;
            }
            if (stk.empty()) return false;
            if (opposite[stk.top()] != ch) return false;
            stk.pop();
        }

        return stk.empty();
    }
};
