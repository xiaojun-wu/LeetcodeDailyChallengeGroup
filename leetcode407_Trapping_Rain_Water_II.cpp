typedef tuple<int,int,int> TIII;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROW = heightMap.size(), COL = heightMap[0].size();
        
        auto cmp = [](auto& lhs,auto& rhs){
            return std::get<0>(lhs) > std::get<0>(rhs);
        };
        
        vector<vector<int>> visited(ROW,vector<int>(COL,0));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<TIII,vector<TIII>,decltype(cmp)> pq(cmp);
        int res = 0;
        
        for(int c = 0;c < COL;c++){
            pq.emplace(heightMap[0][c],0,c);
            pq.emplace(heightMap[ROW - 1][c],ROW - 1,c);
        }
        
        for(int r = 0;r < ROW;r++){
            pq.emplace(heightMap[r][0],r,0);
            pq.emplace(heightMap[r][COL - 1],r,COL - 1);
        }
        
        function<void(int,int,int)> dfs = [&](int r,int c,int val){
            if(visited[r][c] == 2)
                return;
            if(heightMap[r][c] > val){
                if(visited[r][c] == 1)
                    return;
                visited[r][c] = 1;
                pq.emplace(heightMap[r][c],r,c);
                return;
            }
            visited[r][c] = 2;
            res+= (val - heightMap[r][c]);
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || visited[nr][nc])
                    continue;
                dfs(nr,nc,val);
            }
        };
        
        while(!pq.empty()){
            auto[h,r,c] = pq.top();
            pq.pop();
            dfs(r,c,h);
        }
        
        return res;
    }
};
// https://tinyurl.com/rjp4dbwv