class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<long long> heap;
        unordered_map<long long,int> mp;
        int idx = 1, res = 0, count = 0;
        
        for(long long n : nums){
            heap.insert(n);
            heap.insert(n * 2);
        }
        
        for(long long n : heap)
            mp[n] = idx++;
        
        arr = vector<int>(idx,0);
        
        for(long long n : nums){
            res+= count - query(mp[2 * n]);
            update(mp[n]);
            count++;
        }
        
        return res;
    }
private:
    vector<int> arr;
    int lowbit(int n){
        return n & -n;
    }
    void update(int idx){
        while(idx < arr.size()){
            arr[idx]++;
            idx+= lowbit(idx);
        }
    }
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum+= arr[idx];
            idx-= lowbit(idx);
        }
        return sum;
    }
};