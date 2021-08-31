class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        
        function<void(int,int)> dfs = [&](int r,int c) {
            grid[r][c] = '0';
            for(vector<int>& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == '0')
                    continue;
                dfs(nr,nc);
            }
        };
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++)
                if(grid[r][c] == '1'){
                    res++;
                    dfs(r,c);
                }
        
        return res;
    }
};

// https://tinyurl.com/4jn3uj4m