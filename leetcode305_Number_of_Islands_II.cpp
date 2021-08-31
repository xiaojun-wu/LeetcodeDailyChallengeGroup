class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the number of distinct islands
     */
    int numDistinctIslands2(vector<vector<int>> &grid) {
        // write your code here
        const int ROW = grid.size(), COL = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        auto cmp = [](auto& a,auto& b) {
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        };
        set<vector<pair<int,int>>> seen;
        vector<pair<int,int>> cur;
        int res = 0;

        function<void(int,int)> dfs = [&](int r,int c) {
            grid[r][c] = 0;
            cur.emplace_back(r,c);
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == 0)
                    continue;
                dfs(nr,nc);
            }
        };

        function<pair<int,int>(int,int,int)> rotate = [](int r,int c,int row) ->pair<int,int> {
            return {c,row - r - 1};
        };

        function<void(int)> updownflip = [&](int row) {
            for(int i = 0;i < cur.size();i++)
                cur[i].first = row - cur[i].first - 1;
        };

        function<void(int)> leftrightflip = [&](int col) {
            for(int i = 0;i < cur.size();i++)
                cur[i].second = col - cur[i].second - 1;
        };

        function<int(int,int)> checkFlip = [&](int row,int col) ->int {
            int count = 0;
            updownflip(row);
            sort(cur.begin(),cur.end());
            count+= seen.insert(cur).second;
            leftrightflip(col);
            sort(cur.begin(),cur.end());
            count+= seen.insert(cur).second;
            updownflip(row);
            sort(cur.begin(),cur.end());
            count+= seen.insert(cur).second;
            leftrightflip(col);
        } ;

        function<void()> check = [&]() {
            int rowOffSet = ROW, colOffSet = COL;
            int row = 0, col = 0, count = 0;
            for(auto p : cur){
                rowOffSet = min(rowOffSet,p.first);
                colOffSet = min(colOffSet,p.second);
            }
            for(auto& p : cur){
                p.first-= rowOffSet;
                p.second-= colOffSet;
                row = max(row,p.first + 1);
                col = max(col,p.second + 1);
            }

            for(int i = 0;i < 4;i++){
                sort(cur.begin(),cur.end());
                // for(auto& p : cur)
                //     cout<<p.first<<" "<<p.second<<",";
                // cout<<endl;
                count+= seen.insert(cur).second;
                checkFlip(row,col);
                for(int j = 0;j < cur.size();j++)
                    cur[j] = rotate(cur[j].first,cur[j].second,row);
                swap(row,col);
            }
            // cout<<endl;

            if(count > 0)
                res++;
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

// https://tinyurl.com/4mym72uw