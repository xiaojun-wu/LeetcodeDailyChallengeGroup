class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
        cur = nums;
        srand(time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = cur.size() - 1;i > 0;i--){
            int idx = rand() & i;
            swap(cur[idx],cur[i]);
        }
        return cur;
    }
private:
    vector<int> original;
    vector<int> cur;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

 // https://tinyurl.com/33cxnyn2