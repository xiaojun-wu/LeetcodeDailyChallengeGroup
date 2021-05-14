class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        int res = 0;
        unordered_set<int> edges;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int turn = 1;
        bool isFinish = false;
        
        function<void(int,int)> dfs = [&](int r,int c) {
            grid[r][c]++;
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL)
                    continue;
                if(grid[nr][nc] <= 0){
                    edges.insert(nr * COL + nc);
                    grid[nr][nc]--;
                }
                if(grid[nr][nc] == turn)
                    dfs(nr,nc);
            }
        };
        
        function<void(int,int)> clear = [&](int r,int c) {
            grid[r][c]--;
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL)
                    continue;
                if(grid[nr][nc] <= 0){
                    res++;
                    if(grid[nr][nc] < 0)
                        grid[nr][nc]++;
                }
                if(grid[nr][nc] == turn + 1)
                    clear(nr,nc);
            }
        };
        
        while(!isFinish){
            multimap<int,pair<int,int>,greater<int>> mp;
            for(int r = 0;r < ROW;r++)
                for(int c = 0;c < COL;c++)
                    if(grid[r][c] == turn){
                        dfs(r,c);
                        mp.emplace(edges.size(),make_pair(r,c));
                        edges.clear();
                    }
            if(!mp.empty()){
                auto[r,c] = mp.begin()->second;
                clear(r,c);
                turn++;
                for(int r = 0;r < ROW;r++)
                    for(int c = 0;c < COL;c++)
                        if(grid[r][c] < 0)
                            grid[r][c] = turn;
            }
            else{
                isFinish = true;
            }
        }
        
        return res;
    }
};
