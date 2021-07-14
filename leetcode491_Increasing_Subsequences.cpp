class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int SIZE = nums.size(), OFFSET = 100;
        vector<vector<int>> res;
        vector<int> cur;
        int seen[201] = {0};
        
        function<void(int,int)> dfs = [&](int idx,int n) {
            if(idx == SIZE || n == 0){
                if(n == 0)
                    res.push_back(cur);
                return;
            }
            int mp[201] = {0};
            for(int i = idx;i < SIZE;i++){
                if(mp[nums[i] + OFFSET] || (!cur.empty() && cur.back() > nums[i]))
                    continue;
                mp[nums[i] + OFFSET] = 1;
                cur.push_back(nums[i]);
                dfs(i + 1,n - 1);
                cur.pop_back();
            }
        };
        
        for(int i = 2;i <= SIZE;i++)
            dfs(0,i);
        
        return res;
    }
};
