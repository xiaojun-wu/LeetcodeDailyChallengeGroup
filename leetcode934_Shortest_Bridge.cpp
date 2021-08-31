class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        const int ROW = A.size(), COL = A[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int step = 0;
        deque<pair<int,int>> q1, q2;
        
        function<void(int,int)> DFS = [&](int r,int c) {
            A[r][c] = 2;
            for(vector<int> &d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || A[nr][nc] != 1)
                    continue;
                DFS(nr,nc);
            }
        };
        
        for(int r = 0,flag = 1;r < ROW && flag == 1;r++)
            for(int c = 0;c < COL && flag == 1;c++)
                if(A[r][c] == 1){
                    DFS(r,c);
                    flag = 0;
                }
        
        for(int r = 0;r < ROW;r++){
            for(int c = 0;c < COL;c++){
                if(A[r][c] == 1){
                    for(vector<int> &d : dir){
                        int nr = r + d[0], nc = c + d[1];
                        if(nr < 0 || nc < 0 || nr == ROW || nc == COL || A[nr][nc] != 0)
                            continue;
                        q1.emplace_back(r,c);
                        break;
                    }
                }
                else if(A[r][c] == 2){
                    for(vector<int> &d : dir){
                        int nr = r + d[0], nc = c + d[1];
                        if(nr < 0 || nc < 0 || nr == ROW || nc == COL || A[nr][nc] != 0)
                            continue;
                        q2.emplace_back(r,c);
                        break;
                    }
                }
            }
        }
        
        while(true){
            for(int i = q1.size();i > 0;i--){
                auto [r,c] = q1.front();
                q1.pop_front();
                for(vector<int> &d : dir){
                    int nr = r + d[0], nc = c + d[1];
                    if(nr < 0 || nc < 0 || nr == ROW || nc == COL || A[nr][nc] == 1)
                        continue;
                    if(A[nr][nc] == 2)
                        return step;
                    A[nr][nc] = 1;
                    q1.emplace_back(nr,nc);
                }
            }
            step++;
            for(int i = q2.size();i > 0;i--){
                auto [r,c] = q2.front();
                q2.pop_front();
                for(vector<int> &d : dir){
                    int nr = r + d[0], nc = c + d[1];
                    if(nr < 0 || nc < 0 || nr == ROW || nc == COL || A[nr][nc] == 2)
                        continue;
                    if(A[nr][nc] == 1)
                        return step;
                    A[nr][nc] = 2;
                    q2.emplace_back(nr,nc);
                }
            }
            step++;
        }
        
        return -1;
    }
};