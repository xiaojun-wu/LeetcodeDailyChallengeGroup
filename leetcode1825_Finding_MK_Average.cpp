class MKAverage {
public:
    MKAverage(int m, int k) {
        this->_m = m;
        this->_k = k;
        this->sum = 0;
        this->count = 0;
    }
    
    void addElement(int num) {
        /*
        if we already added m elements or more, we have to delete the last m-th one.
        */
        if(less.size() + mid.size() + larger.size() == _m)
            deleteLast();
        // let less and mid heap as full as possible.
        balance();
        q.push_back(num);
        less.insert(num);
        count++;
        if(less.size() > _k){
            auto it = prev(less.end());
            num = *it;
            less.erase(it);
            mid.insert(num);
            sum+= num;
        }
        if(mid.size() > _m - 2 * _k){
            auto it = prev(mid.end());
            num = *it;
            mid.erase(it);
            larger.insert(num);
            sum-= num;
        }
    }
    
    int calculateMKAverage() {
        if(count < _m) return -1;
        return sum / (_m - 2 * _k);
    }
    
    void balance(){
        // keep less and mid as full as possible.
        if(less.size() < _k && mid.size() > 0){
            int num = *mid.begin();
            mid.erase(mid.begin());
            sum-= num;
            less.insert(num);
        }
        if(mid.size() < _m - 2 * _k && larger.size() > 0){
            int num = *larger.begin();
            larger.erase(larger.begin());
            sum+= num;
            mid.insert(num);
        }
    }
    
    void deleteLast(){
        // delete the last _m element added into queue.
        int num = q.front();
        q.pop_front();
        auto it = less.find(num);
        if(it != less.end()){
            less.erase(it);
            return;
        }
        auto it2 = mid.find(num);
        if(it2 != mid.end()){
            sum-= *it2;
            mid.erase(it2);
            return;
        }
        auto it3 = larger.find(num);
        larger.erase(it3);
        return;
    }
private:
    multiset<long> less, mid, larger;
    deque<long> q;
    long _m, _k, sum, count;
};

/*
["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]
[[3,1],[3],[1],[],[10],[],[5],[5],[5],[]]
["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]
[[3,1],[3],[1],[],[10],[],[5],[6],[7],[]]
["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]
[[20,7],[3],[1],[],[10],[],[3],[2],[8],[],[12],[14],[],[20],[],[50],[16],[27],[],[33],[19],[],[100],[],[54],[36],[47],[],[73],[21],[],[10],[],[45],[56],[27],[],[3],[1],[],[10],[],[3],[2],[8],[],[12],[14],[],[20],[],[50],[16],[27],[],[33],[19],[],[100],[],[54],[36],[47],[],[73],[21],[],[10],[],[45],[56],[27],[],[3],[1],[],[10],[],[3],[2],[8],[],[12],[14],[],[20],[],[50],[16],[27],[],[33],[19],[],[100],[],[54],[36],[47],[],[73],[21],[],[10],[],[45],[56],[27],[],[3],[1],[],[10],[],[3],[2],[8],[],[12],[14],[],[20],[],[50],[16],[27],[],[33],[19],[],[100],[],[54],[36],[47],[],[73],[21],[],[10],[],[45],[56],[27],[]]
*/

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */