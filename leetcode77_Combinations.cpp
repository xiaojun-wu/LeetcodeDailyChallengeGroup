class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        
        function<void(int)> dfs = [&](int idx) {
            if(cur.size() == k)
                return res.push_back(cur);
            if(idx == n + 1)
                return;
            for(int i = idx;i <= n;i++){
                cur.push_back(i);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        
        dfs(1);
        
        return res;
    }
};