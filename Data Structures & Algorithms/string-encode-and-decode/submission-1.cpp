class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (auto& str : strs) {
            result += to_string(str.size());
            result += '#';
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while (i < s.size()) {
            int j = i + 1;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            result.emplace_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};
