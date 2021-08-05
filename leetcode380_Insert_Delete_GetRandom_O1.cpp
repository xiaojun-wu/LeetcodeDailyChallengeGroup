class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        idx = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val))
            return false;
        mp[val] = idx;
        if(idx == elements.size())
            elements.push_back(val);
        else
            elements[idx] = val;
        idx++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        int i = mp[val];
        swap(elements[i],elements[idx - 1]);
        mp[elements[i]] = i;
        idx--;
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand() % idx;
        return elements[i];
    }
private:
    unordered_map<int,int> mp;
    vector<int> elements;
    int idx;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */