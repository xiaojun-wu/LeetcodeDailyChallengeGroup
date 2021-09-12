class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // const int ROW = cells.size(), COL = cells[0].size();
        int bottom = row * col + 1;
        vector<vector<int>> grid(row,vector<int>(col,0));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        DSU dsu(grid);
        
        for(int i = cells.size() - 1;i >= 0;i--){
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
            int idx = r * col + c + 1;
            for(vector<int>& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == row || nc == col || grid[nr][nc] == 0) continue;
                dsu.unionNodes(idx,nr * col + nc + 1);
            }
            if(r == 0)
                dsu.unionNodes(idx,0);
            if(r == row - 1)
                dsu.unionNodes(idx,bottom);
            if(dsu.find(0) == dsu.find(bottom))
                return i;
        }
        
        return 0;
    }
private:
    class DSU{
        public:
        DSU(vector<vector<int>>& grid){
            const int ROW = grid.size(), COL = grid[0].size(), N = ROW * COL + 2;
            parents = vector<int>(N,0);
            size = vector<int>(N,1);
            
            for(int i = 1;i < N;i++)
                parents[i] = i;
        }
        int find(int n){
            if(n != parents[n])
                parents[n] = find(parents[n]);
            return parents[n];
        }
        void unionNodes(int a,int b){
            int pa = find(a), pb = find(b);
            if(pa == pb)
                return;
            if(pa == 0 || pb == 0){
                if(pa == 0){
                    parents[pb] = pa;
                    size[pa]+= size[pb];
                }
                else{
                    parents[pa] = pb;
                    size[pb]+= size[pa];
                }
            }
            else{
                if(size[pa] < size[pb]){
                    parents[pa] = pb;
                    size[pb]+= size[pa];
                }
                else{
                    parents[pb] = pa;
                    size[pa]+= size[pb];
                }
            }
        }
        int getSize(int n){
            return size[find(n)];
        }
        private:
        vector<int> parents;
        vector<int> size;
        int groups;
    };
};

// https://tinyurl.com/4r48cb73