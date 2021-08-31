class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        
        function<void(int,int)> DFS = [&](int r,int c) {
            grid[r][c] = 1;
            for(vector<int> &d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] != 0)
                    continue;
                DFS(nr,nc);
            }
        };
        
        for(int r = 0;r < ROW;r++){
            if(grid[r][0] == 0)
                DFS(r,0);
            if(grid[r][COL - 1] == 0)
                DFS(r,COL - 1);
        }
        
        for(int c = 0;c < COL;c++){
            if(grid[0][c] == 0)
                DFS(0,c);
            if(grid[ROW - 1][c] == 0)
                DFS(ROW - 1,c);
        }
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++)
                if(grid[r][c] == 0){
                    res++;
                    DFS(r,c);
                }
        
        return res;
    }
};