class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        heap = map<int,unordered_set<string>>();
        mp = unordered_map<string,int>();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!mp.count(key)){
            mp[key] = 1;
            heap[1].insert(key);
        }
        else{
            int n = mp[key]++;
            heap[n].erase(key);
            if(heap[n].empty())
                heap.erase(n);
            heap[n + 1].insert(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        int n = mp[key]--;
        heap[n].erase(key);
        if(heap[n].empty())
            heap.erase(n);
        if(n == 1)
            mp.erase(key);
        else
            heap[n - 1].insert(key);
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(heap.empty())
            return "";
        return *(heap.rbegin()->second).begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(heap.empty())
            return "";
        return *(heap.begin()->second).begin();
    }
private:
    map<int,unordered_set<string>> heap;
    unordered_map<string,int> mp;
};