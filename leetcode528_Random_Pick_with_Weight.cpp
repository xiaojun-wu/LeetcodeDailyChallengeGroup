class Solution {
public:
    Solution(vector<int>& w) {
        weights = move(w);
        for(int i = 1;i < weights.size();i++)
            weights[i]+= weights[i - 1];
        srand(time(NULL));
    }
    
    int pickIndex() {
        int w = rand() % weights.back() + 1;
        int idx = lower_bound(weights.begin(),weights.end(),w) - weights.begin();
        return idx;
    }
private:
    vector<int> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

 // https://tinyurl.com/4bkfmf8