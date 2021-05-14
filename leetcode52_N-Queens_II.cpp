class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n,false);
        vector<string> cur(n,string(n,'.'));
        
        function<void(int)> dfs = [&](int r) {
            if(r == n){
                res++;
                return;
            }
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
                    col[c] = true;
                    cur[r][c] = 'Q';
                    dfs(r + 1);
                    col[c] = false;
                    cur[r][c] = '.';
                }
            }
        };
        
        dfs(0);
        
        return res;
    }
};