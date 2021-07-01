class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets = vector<list<pair<int,int>>>(SIZE);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % SIZE;
        bool isExist = false;
        
        for(auto it = buckets[hash].begin();it != buckets[hash].end() && !isExist;it++)
            if(it->first == key){
                isExist = true;
                it->second = value;
            }
        if(!isExist)
            buckets[hash].emplace_back(key,value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % SIZE;
        int val = -1;
        
        for(auto it = buckets[hash].begin();it != buckets[hash].end() && val == -1;it++)
            if(it->first == key)
                val = it->second;
        
        return val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % SIZE;
        int val = -1;
        
        for(auto it = buckets[hash].begin();it != buckets[hash].end() && val == -1;it++)
            if(it->first == key){
                buckets[hash].erase(it);
                return;
            }
    }
private:
    const int SIZE = 9973;
    vector<list<pair<int,int>>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

 // https://tinyurl.com/ewshnvx5