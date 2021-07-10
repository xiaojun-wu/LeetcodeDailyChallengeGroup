typedef pair<int,int> PII;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        bool dp[51][51] = {0};
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        multimap<int,pair<int,int>> heap;
        heap.emplace(grid[0][0],make_pair(0,0));
        dp[0][0] = true;
        
        while(!heap.empty()){
            auto it = heap.begin();
            int dis = it->first, r = it->second.first, c = it->second.second;
            if(r == N - 1 && c == N - 1)
                return dis;
            heap.erase(it);
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == N || nc == N || dp[nr][nc])
                    continue;
                dp[nr][nc] = true;
                heap.emplace(max(dis,grid[nr][nc]),make_pair(nr,nc));
            }
        }
        
        return -1;
    }
};