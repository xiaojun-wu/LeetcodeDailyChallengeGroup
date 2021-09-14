class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        const int ROW = mat.size(), COL = mat[0].size(), TOTAL = ROW * COL;
        vector<int> seen(1 << TOTAL,0);
        int initState = 0, step = 0;
        deque<int> q;
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0;c < COL;c++)
                initState|= (mat[r][c] << (r * COL + c));
        
        if(initState == 0)
            return 0;
        seen[initState] = 1;
        q.push_back(initState);
        
        function<int(int,int)> flip = [&](int state,int pos) ->int {
            state^= (1 << pos);
            int r = pos / COL, c = pos % COL;
            if(r > 0)
                state^= (1 << (pos - COL));
            if(r < ROW - 1)
                state^= (1 << (pos + COL));
            if(c > 0)
                state^= (1 << (pos - 1));
            if(c < COL - 1)
                state^= (1 << (pos + 1));
            return state;
        };
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                int state = q.front();
                q.pop_front();
                for(int j = 0;j < ROW * COL;j++){
                    int n_state = flip(state,j);
                    if(!seen[n_state]){
                        seen[n_state] = 1;
                        q.push_back(n_state);
                    }
                }
                if(seen[0])
                    return step + 1;
            }
            step++;
        }
        
        return -1;
    }
};

// https://tinyurl.com/avpstt54