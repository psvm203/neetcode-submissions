class TimeMap {
   public:
    map<string, vector<pair<string, int>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        auto& v = mp[key];
        int n = v.size();

        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (v[md].second > timestamp) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }

        string result;
        if (lo - 1 >= 0) result = v[lo - 1].first;
        return result;
    }
};
