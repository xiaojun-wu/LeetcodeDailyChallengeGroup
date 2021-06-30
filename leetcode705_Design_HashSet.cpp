class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets = vector<list<int>>(SIZE);
    }
    
    void add(int key) {
        if(!contains(key))
            buckets[key % SIZE].push_back(key);
    }
    
    void remove(int key) {
        int hash = key % SIZE;
        for(auto it = buckets[hash].begin();it != buckets[hash].end();it++)
            if(*it == key){
                buckets[hash].erase(it);
                break;
            }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = key % SIZE;
        for(auto it = buckets[hash].begin();it != buckets[hash].end();it++)
            if(*it == key)
                return true;
        return false;
    }
private:
    const int SIZE = 9973;
    vector<list<int>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */