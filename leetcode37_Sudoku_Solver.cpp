class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // backtracking.
        vector<vector<char>> origin = board;
        vector<vector<bool>> rows(9,vector<bool>(9,false));
        vector<vector<bool>> cols(9,vector<bool>(9,false));
        vector<vector<bool>> blocks(9,vector<bool>(9,false));
        
        for(int r = 0;r < 9;r++)
            for(int c = 0;c < 9;c++)
                if(board[r][c] != '.'){
                    rows[r][board[r][c] - '1'] = true;
                    cols[c][board[r][c] - '1'] = true;
                    blocks[(r / 3) * 3 + (c / 3)][board[r][c] - '1'] = true;
                }
        
        function<pair<int,int>(int,int)> getNext = [&](int r,int c) ->pair<int,int> {
            c++;
            if(c == 9){
                c = 0;
                r++;
            }
            return {r,c};
        };
        
        function<bool(int,int)> dfs = [&](int r,int c) ->bool {
            if(r == 9)
                return true;
            if(origin[r][c] != '.'){
                auto[nr,nc] = getNext(r,c);
                return dfs(nr,nc);
            }
            for(int i = 0;i < 9;i++){
                if(!rows[r][i] && !cols[c][i] && !blocks[(r / 3) * 3 + (c / 3)][i]){
                    board[r][c] = i + '1';
                    rows[r][i] = true;
                    cols[c][i] = true;
                    blocks[(r / 3) * 3 + (c / 3)][i] = true;
                    auto[nr,nc] = getNext(r,c);
                    if(dfs(nr,nc))
                        return true;
                    rows[r][i] = false;
                    cols[c][i] = false;
                    blocks[(r / 3) * 3 + (c / 3)][i] = false;
                }
            }
            return false;
        };
        
        dfs(0,0);
        
        return;
    }
};