class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        /*
        The main idea is do it reversely.
        1. We remove the brick on grid which will be hit
        2. Group ceiling bricks together.
        3. We put the brick back to grid.
        4. If ceilling connect to new bricks, they are fallen bricks after apply hits.
        5. Count how many bricks will be fallen.

        Union_find:
        We use union_find to group the bricks if they are connected.
        Than we add brick back to grid backward, if two different group connect, group them, if a group connect to ceiling bricks, the number of groups brick are fallen bricks.

        DFS:
        After remove hit bricks, We mark ceilling brick 2, it to differ from the fallen bricks.
        Than we add hit bricks back, check if there has ceiling brick around the hit brick, if so, search from this brick.
        */
        const int ROW = grid.size(), COL = grid[0].size();
        vector<int> res(hits.size(),0);
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(vector<int>& hit : hits){
            if(grid[hit[0]][hit[1]] == 0)
                hit[0] = -1;
            else
                grid[hit[0]][hit[1]] = 0;
        }
        
        DSU dsu(grid);
        
        for(int i = hits.size() - 1;i >= 0;i--){
            if(hits[i][0] == -1) continue;
            grid[hits[i][0]][hits[i][1]] = 1;
            int r = hits[i][0], c = hits[i][1], idx = r * COL + c + 1;
            int original_size = dsu.getSize(0);
            for(vector<int>& dir : dirs){
                int nr = r + dir[0], nc = c + dir[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == 0)
                    continue;
                dsu.unionNodes(idx,nr * COL + nc + 1);
            }
            if(r == 0){
                dsu.unionNodes(idx,0);
            }
            int afterSize = dsu.getSize(0);
            if(afterSize - original_size != 0)
                res[i] = afterSize - original_size - 1;
                
        }
        
        return res;
    }
private:
    class DSU{
        public:
        DSU(vector<vector<int>>& grid){
            const int ROW = grid.size(), COL = grid[0].size(), N = ROW * COL + 1;
            parents = vector<int>(N,0);
            size = vector<int>(N,1);
            vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            
            for(int i = 1;i < N;i++)
                parents[i] = i;
            
            for(int c = 0;c < COL;c++)
                if(grid[0][c] != 0)
                    unionNodes(c + 1,0);
            
            for(int r = 0;r < ROW;r++)
                for(int c = 0;c < COL;c++){
                    if(grid[r][c] == 0) continue;
                    int idx = r * COL + c + 1;
                    for(vector<int>& dir : dirs){
                        int nr = r + dir[0], nc = c + dir[1];
                        if(nr < 0 || nc < 0 || nr == ROW || nc == COL || grid[nr][nc] == 0)
                            continue;
                        unionNodes(idx,nr * COL + nc + 1);
                    }
                }
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