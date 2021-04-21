class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> presum(nums.size(),0);
        set<long long> heap;
        unordered_map<long long,int> mp;
        int idx = 1, res = 0;
        presum[0] = nums[0];
        
        for(int i = 1;i < nums.size();i++)
            presum[i] = presum[i - 1] + nums[i];
        
        for(long long n : presum){
            heap.insert(n);
            heap.insert(n - lower);
            heap.insert(n - upper);
        }
        
        heap.insert(0);
        
        for(long long n : heap)
            mp[n] = idx++;
        
        arr = vector<int>(heap.size() + 1,0);
        update(mp[0]);
        
        for(long long n : presum){
            res+= query(mp[n - lower]) - query(mp[n - upper] - 1);
            update(mp[n]);
        }
        
        return res;
    }
private:
    vector<int> arr;
    int lowbit(int n){
        return n & -n;
    }
    void update(int i){
        while(i < arr.size()){
            arr[i]++;
            i+= lowbit(i);
        }
    }
    int query(int i){
        int sum = 0;
        while(i > 0){
            sum+= arr[i];
            i-= lowbit(i);
        }
        return sum;
    }
};