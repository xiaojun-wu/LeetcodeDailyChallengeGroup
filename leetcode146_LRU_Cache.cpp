class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        int v = (*mp[key]).second;
        lst.erase(mp[key]);
        mp[key] = lst.emplace(lst.end(),key,v);
        return v;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            if(size < capacity)
                size++;
            else{
                int k = (*lst.begin()).first;
                mp.erase(k);
                lst.erase(lst.begin());
            }
            mp[key] = lst.emplace(lst.end(),key,value);
        }
        else{
            lst.erase(mp[key]);
            mp[key] = lst.emplace(lst.end(),key,value);
        }
    }
private:
    list<pair<int,int>> lst;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int capacity, size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */