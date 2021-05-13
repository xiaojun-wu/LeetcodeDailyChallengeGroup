class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int SIZE = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == SIZE){
                res.push_back(cur);
                return;
            }
            dfs(idx + 1);
            cur.push_back(nums[idx]);
            dfs(idx + 1);
            cur.pop_back();
        };
        
        dfs(0);
        
        return res;
    }
};
// https://tinyurl.com/yy8txe6d