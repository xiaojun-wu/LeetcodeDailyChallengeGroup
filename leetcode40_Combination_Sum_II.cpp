class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        const int SIZE = candidates.size();
        vector<vector<int>> res;
        vector<int> cur;
        int sum = 0;
        
        function<void(int,int)> dfs = [&](int idx,int pre) {
            if(sum == target)
                return res.push_back(cur);
            if(idx == SIZE)
                return;
            if(sum + candidates[idx] > target)
                return;
            if(pre != candidates[idx]){
                sum+= candidates[idx];
                cur.push_back(candidates[idx]);
                dfs(idx + 1,pre);
                sum-= candidates[idx];
                cur.pop_back();
            }
            dfs(idx + 1,candidates[idx]);
        };
        
        dfs(0,-1);
        
        return res;
    }
};