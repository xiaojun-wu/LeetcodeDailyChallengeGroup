class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int ROW = grid.size(), COL = grid[0].size();
        DSU dsu(ROW * COL * 2);
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++){
                int a = r * COL * 2 + c * 2, b = a + 1;
                if(c > 0)
                    dsu.unionNodes(a,a - 1);
                if(grid[r][c] == ' ')
                    dsu.unionNodes(a,b);
                
                if(r > 0){
                    int x = grid[r - 1][c] == '/'? b - COL * 2:a - COL * 2;
                    int y = grid[r][c] == '/'?a:b;
                    dsu.unionNodes(x,y);
                }
                
                if(c > 0)
                    dsu.unionNodes(a,a - 1);
            }
        
        return dsu.getGroups();
    }
private:
    class DSU{
        public:
        DSU(int n){
            parents = vector<int>(n,0);
            rank = vector<int>(n,0);
            groups = n;
            
            for(int i = 0;i < n;i++)
                parents[i] = i;
        }
        int findParent(int n){
            if(n != parents[n])
                parents[n] = findParent(parents[n]);
            return parents[n];
        }
        void unionNodes(int a,int b){
            if(a < 0 || b < 0)
                return;
            int parentA = findParent(a), parentB = findParent(b);
            if(parentA == parentB)
                return;
            groups--;
            if(rank[parentA] > rank[parentB])
                parents[parentB] = parentA;
            else if(rank[parentA] < rank[parentB])
                parents[parentA] = parentB;
            else{
                rank[parentA]++;
                parents[parentB] = parentA;
            }
        }
        int getGroups(){
            return groups;
        }
        private:
        vector<int> parents;
        vector<int> rank;
        int groups;
    };
};

// https://tinyurl.com/dbcwy6sa