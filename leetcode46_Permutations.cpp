class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int SIZE = nums.size();
        vector<vector<int>> res;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == SIZE)
                return res.push_back(nums);
            for(int i = idx;i < SIZE;i++){
                swap(nums[i],nums[idx]);
                dfs(idx + 1);
                swap(nums[i],nums[idx]);
            }
        };
        
        dfs(0);
        
        return res;
    }
};