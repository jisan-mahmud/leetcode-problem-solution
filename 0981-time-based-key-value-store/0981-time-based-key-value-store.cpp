class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> key_timeValue_map;
public:
    TimeMap() {
        key_timeValue_map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        key_timeValue_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!key_timeValue_map.count(key))
            return "";

        auto &v = key_timeValue_map[key];

        auto it = upper_bound(
            v.begin(), v.end(), timestamp,
            [](int value, const pair<int, string>& p) {
                return value < p.first;
            }
        );

        if (it == v.begin())
            return "";

        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();   
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */