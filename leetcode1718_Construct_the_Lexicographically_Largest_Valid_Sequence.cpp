class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        const int SIZE = n * 2 - 1;
        vector<int> res(SIZE,0);
        vector<int> taken(n + 1,0);
        
        function<bool(int)> dfs = [&](int idx) ->bool {
            if(idx == SIZE)
                return true;
            if(res[idx] != 0)
                return dfs(idx + 1);
            for(int i = n;i >= 2;i--){
                if(idx + i < SIZE && res[idx + i] == 0 && taken[i] == 0){
                    taken[i] = 1;
                    res[idx] = i;
                    res[idx + i] = i;
                    if(dfs(idx + 1))
                        return true;
                    taken[i] = 0;
                    res[idx] = 0;
                    res[idx + i] = 0;
                }
            }
            
            if(taken[1] == 0){
                res[idx] = 1;
                taken[1] = 1;
                if(dfs(idx + 1))
                    return true;
                res[idx] = 0;
                taken[1] = 0;
            } 
            
            return false;
        };
        
        dfs(0);
        
        return res;
    }
};