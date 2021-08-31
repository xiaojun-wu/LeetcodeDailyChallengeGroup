class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        // write your code here
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        set<vector<pair<int,int>>> seen;
        vector<pair<int,int>> cur;
        int res = 0;

        function<void(int,int)> dfs = [&](int r,int c) {
            grid[r][c] = 0;
            cur.emplace_back(r,c);
            for(auto& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == 0)
                    continue;
                dfs(nr,nc);
            }
        };

        function<void()> check = [&]() {
            int rowOffset = ROW, colOffset = COL;

            for(auto& p : cur){
                rowOffset = min(p.first,rowOffset);
                colOffset = min(p.second,colOffset);
            }

            for(auto& p : cur){
                p.first-= rowOffset;
                p.second-= colOffset;
            }

            sort(cur.begin(),cur.end());
            res+= seen.insert(cur).second;
        };

        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++)
                if(grid[r][c]){
                    dfs(r,c);
                    check();
                    cur.clear();
                }

        return res;
    }
};