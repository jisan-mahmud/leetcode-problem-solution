class LFUCache {
private:
    int limit, min_freq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> key_value;

    // frequency -> keys
    unordered_map<int, list<int>> freq_keys;

    // key -> iterator inside freq_keys[frequency]
    unordered_map<int, list<int>::iterator> address;

public:
    LFUCache(int capacity) {
        limit = capacity;
        min_freq = 0;
    }

    int get(int key) {
        if (!key_value.count(key))
            return -1;

        int freq = key_value[key].second;

        // Remove from old frequency list
        freq_keys[freq].erase(address[key]);
        address.erase(key);

        // Increase frequency
        freq++;
        key_value[key].second = freq;

        // Add to new frequency list
        freq_keys[freq].push_back(key);
        address[key] = prev(freq_keys[freq].end());

        // If old minimum frequency became empty
        if (freq - 1 == min_freq && freq_keys[freq - 1].empty())
            min_freq = freq;

        return key_value[key].first;
    }

    void put(int key, int value) {
        if (limit == 0)
            return;

        // Existing key
        if (key_value.count(key)) {
            get(key);
            key_value[key].first = value;
            return;
        }

        // Cache full
        if (key_value.size() == limit) {
            auto node = freq_keys[min_freq].begin();

            int oldKey = *node;

            address.erase(oldKey);
            key_value.erase(oldKey);
            freq_keys[min_freq].erase(node);
        }

        // New key starts at frequency 1
        key_value[key] = {value, 1};

        freq_keys[1].push_back(key);
        address[key] = prev(freq_keys[1].end());

        min_freq = 1;
    }
};