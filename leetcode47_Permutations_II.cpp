class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int SIZE = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == SIZE)
                return res.push_back(nums);
            unordered_set<int> seen;
            for(int i = idx;i < SIZE;i++){
                if(seen.count(nums[i]))
                    continue;
                swap(nums[i],nums[idx]);
                seen.insert(nums[idx]);
                dfs(idx + 1);
                swap(nums[i],nums[idx]);
            }
        };
        
        dfs(0);
        
        return res;
    }
};
// https://tinyurl.com/8897ebfx