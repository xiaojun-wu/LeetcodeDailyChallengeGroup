/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        const int SIZE = operators.size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<int> res;
        DSU dsu(n * m);
        
        for(auto& op : operators){
            int r = op.x, c = op.y;
            dsu.beIsland(op.x * m + op.y);
            for(auto& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == n || nc == m || !dsu.isIsland(nr * m + nc))
                    continue;
                dsu.unionNodes(r * m + c,nr * m + nc);
            }
            res.push_back(dsu.getIslands());
        }

        return res;
    }
private:
    class DSU{
        public:
        DSU(int n){
            arr = vector<int>(n,-1);
            rank = vector<int>(n,0);
            groups = 0;
        }
        void beIsland(int n){
            if(arr[n] == -1){
                arr[n] = n;
                groups++;
            }
        }
        int findParent(int n){
            if(n != arr[n]){
                arr[n] = findParent(arr[n]);
            }
            return arr[n];
        }
        void unionNodes(int a,int b){
            int rootA = findParent(a), rootB = findParent(b);
            if(rootA == rootB)
                return;
            if(rank[rootA] < rank[rootB])
                arr[rootA] = rootB;
            else if(rank[rootB] < rank[rootA])
                arr[rootB] = rootA;
            else{
                arr[rootA] = rootB;
                rank[rootB]++;
            }
            groups--;
        }
        int getIslands(){
            return groups;
        }
        int isIsland(int n){
            return arr[n] != -1;
        }
        private:
            vector<int> arr;
            vector<int> rank;
            int groups;
    };
};

// https://tinyurl.com/4mym72uw