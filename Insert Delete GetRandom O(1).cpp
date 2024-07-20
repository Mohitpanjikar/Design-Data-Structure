//Link - https://leetcode.com/problems/insert-delete-getrandom-o1/description/
class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mpp;
    RandomizedSet() {}

    bool insert(int val) {
        // check if present in map or not -
        if (mpp.find(val) != mpp.end()) {
            return false;
        }
        v.push_back(val);
        mpp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mpp.find(val) == mpp.end()) {
            return false;
        }
        // finding out the element and taking it to the end of vector -
        // pop it out and remove from the map too
        // take the lastelement to the idx and update the mpp
        int idx = mpp[val];
        int lastElement = v.back();
        v.back() = val;

        v[idx] = lastElement;
        mpp[lastElement] = idx;

        v.pop_back();
        mpp.erase(val);
        return true;
    }

    int getRandom() {
        int n = v.size();
        int randomIndex = rand() % n;
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
