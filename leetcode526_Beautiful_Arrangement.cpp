class Solution {
public:
    int countArrangement(int n) {
        // backtracking
        vector<bool> isTaken(n + 1,false);
        int res = 0;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == n + 1){
                res++;
                return;
            }
            for(int i = 1;i <= n;i++){
                if((idx % i != 0 && i % idx != 0) || isTaken[i])
                    continue;
                isTaken[i] = true;
                dfs(idx + 1);
                isTaken[i] = false;
            }
        };
        
        dfs(1);
        
        return res;
    }
};