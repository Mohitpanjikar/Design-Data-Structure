class MyHashMap {
public:
    vector<list<pair<int, int>>> bucket;
    int size = 10000;
    MyHashMap() { bucket.resize(size); }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket_no = key % size;
        auto& chain = bucket[bucket_no];
        for (auto& it : chain) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        int bucket_no = key % size;
        auto& chain = bucket[bucket_no];
        if (chain.empty())
            return -1;

        for (auto& it : chain) {
            if (it.first == key)
                return it.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        int bucket_no = key % size;
        auto& chain = bucket[bucket_no];

        for (auto it = chain.begin(); it != chain.end();) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
            it++;
        }
    }
};
