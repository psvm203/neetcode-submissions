class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
        for (auto& token : tokens) {
            if (isdigit(token[0]) || isdigit(token[1])) {
                stk.emplace_back(stoi(token));
                continue;
            }
            int a = stk[stk.size() - 2];
            int b = stk.back();
            stk.pop_back();
            stk.pop_back();
            if (token == "+") {
                stk.emplace_back(a + b);
                continue;
            }
            if (token == "-") {
                stk.emplace_back(a - b);
                continue;
            }
            if (token == "*") {
                stk.emplace_back(a * b);
                continue;
            }
            if (token == "/") {
                stk.emplace_back(a / b);
            }
        }

        return stk[0];
    }
};
