class RandomizedCollection {
public:
    // used 43 mins to implement an O(1) solution and with one wa.
    /** Initialize your data structure here. */
    RandomizedCollection() {
        this->size = 0;
    }
    ls
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool isNotExist = !mp.count(val);
        if(nums.size() == size)
            nums.push_back(val);
        else
            nums[size] = val;
        mp[val].insert(size++);
        return isNotExist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool isExist = mp.count(val);
        if(!isExist)
            return isExist;
        auto it = mp[val].begin();
        int idx = *it, idx2 = size - 1, val2 = nums[idx2];
        mp[val].erase(it);
        nums[idx] = nums[idx2];
        if(mp[val].empty())
            mp.erase(val);
        if(size > 1 && idx != idx2){
            mp[val2].erase(idx2);
            mp[val2].insert(idx);
        }
        size--;
        return isExist;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % size;
        return nums[idx];
    }
private:
    unordered_map<int,unordered_set<int>> mp;
    vector<int> nums;
    int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */