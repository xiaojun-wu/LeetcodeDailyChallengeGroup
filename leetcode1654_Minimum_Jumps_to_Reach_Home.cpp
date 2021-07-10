class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0)
            return 0;
        unordered_set<int> forbi(forbidden.begin(),forbidden.end());
        int visited[6001] = {0};
        deque<pair<int,int>> q;
        q.emplace_back(0,0);
        visited[0] = 1;
        int step = 0;
        
        while(!q.empty() && step <= 4000){
            for(int i = q.size();i > 0;i--){
                auto[pos,isback] = q.front();
                q.pop_front();
                if(isback == 0){
                    if(pos - b >= 0 && !visited[pos - b] && !forbi.count(pos - b)){
                        visited[pos - b] = 1;
                        q.emplace_back(pos - b,1);
                    }
                }
                if(pos + a <= 6000 && !visited[pos + a] && !forbi.count(pos + a)){
                    visited[pos + a] = 1;
                    q.emplace_back(pos + a,0);
                }
                if(visited[x] == 1)
                    return step + 1;
            }
            step++;
        }
        
        return -1;
    }
};
// https://tinyurl.com/xnz4aa2c