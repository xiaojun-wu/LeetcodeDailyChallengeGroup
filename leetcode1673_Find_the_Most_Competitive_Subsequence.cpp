class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        /*
        monotonic stack
        TC: O(N), SC: O(N).
        */
        const int SIZE = nums.size();
        vector<int> res;
        
        for(int i = 0;i < SIZE;i++){
            while(!res.empty() && res.back() > nums[i] && res.size() + (SIZE - i) > k)
                res.pop_back();
            if(res.size() < k)
                res.push_back(nums[i]);
        }
        
        return res;
    }
};
// https://tinyurl.com/47a9cy62