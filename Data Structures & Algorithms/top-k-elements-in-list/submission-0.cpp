class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        multimap<int, int> frequents;
        for (auto& [num, count] : counts) {
            frequents.emplace(count, num);
        }

        vector<int> result;
        auto it = frequents.rbegin();
        while (k--) {
            result.emplace_back(it->second);
            it++;
        }
        return result;
    }
};
