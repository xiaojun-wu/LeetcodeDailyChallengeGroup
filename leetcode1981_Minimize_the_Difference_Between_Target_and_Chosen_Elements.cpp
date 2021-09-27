class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int ROW = mat.size(), COL = mat[0].size();
        vector<int> dp(target + 2,0);
        dp[0] = 1;
        dp[target + 1] = INT_MAX;
        int res = INT_MAX;
        
        for(int i = 0;i < ROW;i++)
            sort(mat[i].begin(),mat[i].end());
        
        for(int r = 0;r < ROW;r++){
            vector<int> next(target + 2,0);
            next[target + 1] = INT_MAX;
            for(int c = 0;c < COL;c++){
                for(int t = target;t >= 0;t--){
                    if(dp[t] == 0)
                        continue;
                    int val = mat[r][c] + t;
                    if(val <= target)
                        next[val] = 1;
                    else
                        next[target + 1] = min(next[target + 1],val);
                }
                if(dp[target + 1] != INT_MAX)
                    next[target + 1] = min(next[target + 1],dp[target + 1] + mat[r][c]);
            }
            swap(next,dp);
        }
        
        res = min(res,dp[target + 1] - target);
        
        for(int i = target;i >= 0;i--)
            if(dp[i] != 0){
                res = min(res,target - i);
                break;
            }
        
        return res;
    }
};

// https://tinyurl.com/cxr6tw3k