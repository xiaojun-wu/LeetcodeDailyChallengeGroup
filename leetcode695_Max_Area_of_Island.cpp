class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        int res = 0, count = 0;
        
        function<void(int,int)> dfs = [&](int r,int c) {
            count++;
            grid[r][c] = 0;
            for(auto& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == 0)
                    continue;
                dfs(nr,nc);
            }
        };
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++)
                if(grid[r][c]){
                    dfs(r,c);
                    res = max(res,count);
                    count = 0;
                }
        
        return res;
    }
};

// https://tinyurl.com/unctbenf