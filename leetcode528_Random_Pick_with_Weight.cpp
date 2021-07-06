class Solution {
public:
    Solution(vector<int>& w) {
        presum = vector<int>(1,0);
        
        for(int n : w)
            presum.push_back(presum.back() + n);
        
        srand(time(NULL));
    }
    
    int pickIndex() {
        int sum = presum.back();
        int pickNum = rand() % sum + 1;
        int idx = lower_bound(presum.begin(),presum.end(),pickNum) - presum.begin() - 1;
        
        return idx;
    }
private:
    vector<int> presum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

 // https://tinyurl.com/4bkfmf8