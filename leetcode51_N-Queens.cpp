class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> col(n,false);
        vector<string> cur(n,string(n,'.'));
        
        function<void(int)> dfs = [&](int r) {
            if(r == n)
                return res.push_back(cur);
            for(int c = 0;c < n;c++){
                if(col[c])
                    continue;
                bool isCross = false;
                for(int i = 1;r - i >= 0 && (c - i >= 0 || c + i < n) && !isCross;i++){
                    if(c - i >= 0 && cur[r - i][c - i] != '.')
                        isCross = true;
                    if(c + i < n && cur[r - i][c + i] != '.')
                        isCross = true;
                }
                if(!isCross){
                    cur[r][c] = 'Q';
                    col[c] = true;
                    dfs(r + 1);
                    cur[r][c] = '.';
                    col[c] = false;
                }
            }
        };
        
        dfs(0);
        
        return res;
    }
};