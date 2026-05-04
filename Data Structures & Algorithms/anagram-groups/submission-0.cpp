class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, vector<string>> anagrams;
        for (auto& str : strs) {
            multiset st(str.begin(), str.end());
            anagrams[st].emplace_back(str);
        }

        vector<vector<string>> result;
        for (auto& [_, anagram] : anagrams) {
            result.emplace_back(anagram);
        }
        return result;
    }
};
