class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        this->idx = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        mp[val] = idx;
        if(arr.size() == idx)
            arr.push_back(val);
        else
            arr[idx] = val;
        idx++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val)){
            return false;
        }
        int i = mp[val];
        mp.erase(val);
        arr[i] = arr[idx - 1];
        if(i != idx - 1){
            mp[arr[i]] = i;
        }
        idx--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % idx];
    }
private:
    unordered_map<int,int> mp;
    vector<int> arr;
    int idx;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */