class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        const int QSIZE = queries.size();
        vector<bool> res(QSIZE,true);
        vector<bool> visited(n + 1,false);
        DSU dsu(n);
        
        if(threshold == 0)
            return res;
        
        for(int i = threshold + 1;i <= n;i++){
            if(!visited[i]){
                visited[i] = true;
                for(int j = i * 2;j <= n;j+= i){
                    dsu.unionNodes(i,j);
                    visited[j] = true;
                }
            }
        }
        
        for(int i = 0;i < QSIZE;i++)
            if(!dsu.isConnect(queries[i][0],queries[i][1]))
                res[i] = false;
        
        return res;
    }
private:
    class DSU{
        public:
        DSU(int n){
            parents = vector<int>(n + 1,0);
            rank = vector<int>(n + 1,0);
            
            for(int i = 1;i <= n;i++)
                parents[i] = i;
        }
        int find(int n){
            if(n != parents[n])
                parents[n] = find(parents[n]);
            return parents[n];
        }
        bool isConnect(int a,int b){
            int rootA = find(a);
            int rootB = find(b);
            return rootA == rootB;
        }
        void unionNodes(int a,int b){
            int rootA = find(a), rootB = find(b);
            if(rootA == rootB)
                return;
            if(rank[rootA] < rank[rootB])
                parents[rootA] = rootB;
            else if(rank[rootA] > rank[rootB])
                parents[rootB] = rootA;
            else{
                parents[rootB] = rootA;
                rank[rootA]++;
            }
        }
        private:
        vector<int> parents;
        vector<int> rank;
    };
};