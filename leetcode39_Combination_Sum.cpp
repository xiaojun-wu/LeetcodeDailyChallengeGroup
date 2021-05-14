class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        const int SIZE = candidates.size();
        vector<vector<int>> res;
        vector<int> cur;
        int sum = 0;
        
        function<void(int)> dfs = [&](int idx) {
            if(sum == target)
                return res.push_back(cur);
            if(idx == SIZE)
                return;
            dfs(idx + 1);
            while(sum + candidates[idx] <= target){
                cur.push_back(candidates[idx]);
                sum+= candidates[idx];
                dfs(idx + 1);
            }
            while(!cur.empty() && cur.back() == candidates[idx]){
                cur.pop_back();
                sum-= candidates[idx];
            }
        };
        
        dfs(0);
        
        return res;
    }
};
// https://tinyurl.com/2bz6ee7n