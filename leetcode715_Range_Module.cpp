class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto litr = lower_bound(arr.begin(),arr.end(),left);
        auto ritr = upper_bound(arr.begin(),arr.end(),right);
        int l = lower_bound(arr.begin(),arr.end(),left) - arr.begin();
        int r = upper_bound(arr.begin(),arr.end(),right) - arr.begin();
        vector<int> mid;
        if(l % 2 == 0)
            mid.push_back(left);
        if(r % 2 == 0)
            mid.push_back(right);
        vector<int> next;
        next.insert(next.end(),arr.begin(),litr);
        next.insert(next.end(),mid.begin(),mid.end());
        next.insert(next.end(),ritr,arr.end());
        swap(arr,next);
    }
    
    bool queryRange(int left, int right) {
        int idx = upper_bound(arr.begin(),arr.end(),left) - arr.begin();
        idx--;
        if(idx < 0 || idx % 2 == 1)
            return false;
        return arr[idx + 1] >= right;
    }
    
    void removeRange(int left, int right) {
        auto litr = lower_bound(arr.begin(),arr.end(),left);
        auto ritr = upper_bound(arr.begin(),arr.end(),right);
        int l = lower_bound(arr.begin(),arr.end(),left) - arr.begin();
        int r = upper_bound(arr.begin(),arr.end(),right) - arr.begin();
        vector<int> mid;
        if(l % 2 == 1)
            mid.push_back(left);
        if(r % 2 == 1)
            mid.push_back(right);
        vector<int> next;
        next.insert(next.end(),arr.begin(),litr);
        next.insert(next.end(),mid.begin(),mid.end());
        next.insert(next.end(),ritr,arr.end());
        swap(arr,next);
    }
private:
    vector<int> arr;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */