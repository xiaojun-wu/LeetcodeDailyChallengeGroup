class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        auto it = mp[key];
        int val = std::get<1>(*it), freq = std::get<2>(*it);
        freq_mp[freq].erase(it);
        if(freq_mp[freq].empty())
            freq_mp.erase(freq);
        mp[key] = freq_mp[freq + 1].emplace(freq_mp[freq + 1].end(),key,val,freq + 1);
        return val;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        if(!mp.count(key)){
            if(size == capacity){
                auto it = freq_mp.begin();
                auto it2 = (it->second).begin();
                int k = std::get<0>(*it2), freq = std::get<2>(*it2);
                (it->second).erase(it2);
                mp.erase(k);
                if((it->second).empty())
                    freq_mp.erase(freq);
            }
            else
                size++;
            mp[key] = freq_mp[1].emplace(freq_mp[1].end(),key,value,1);
        }
        else{
            auto it = mp[key];
            int freq = std::get<2>(*it);
            freq_mp[freq].erase(it);
            if(freq_mp[freq].empty())
                freq_mp.erase(freq);
            mp[key] = freq_mp[freq + 1].emplace(freq_mp[freq + 1].end(),key,value,freq + 1);
        }
    }
private:
    map<int,list<tuple<int,int,int>>> freq_mp;
    unordered_map<int,list<tuple<int,int,int>>::iterator> mp;
    int capacity, size;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */