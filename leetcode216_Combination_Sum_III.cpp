class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // backtracking.
        vector<vector<int>> res;
        vector<int> cur;
        int sum = 0;
        
        function<void(int)> dfs = [&](int idx) {
            if(sum == n && cur.size() == k){
                res.push_back(cur);
                return;
            }
            if(cur.size() == k || idx == 10)
                return;
            for(int i = idx;i < 10;i++){
                if(sum + i <= n){
                    cur.push_back(i);
                    sum+= i;
                    dfs(i + 1);
                    cur.pop_back();
                    sum-= i;
                }
            }
        };
        
        dfs(1);
        
        return res;
    }
};