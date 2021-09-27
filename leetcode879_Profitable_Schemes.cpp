class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int SIZE = group.size(), MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1,vector<int>(minProfit + 1,0));
        int res = 0;
        dp[0][0] = 1;
        
        for(int i = 0;i < SIZE;i++){
            int pf = profit[i], g = group[i];
            for(int j = n - g;j >= 0;j--){
                for(int k = minProfit;k >= 0;k--){
                    if(dp[j][k]){
                        int m = min(pf + k,minProfit);
                        dp[j + g][m] = (dp[j + g][m] + dp[j][k]) % MOD;
                    }
                }
            }
        }
        
        for(int i = 0;i <= n;i++)
            res = (res + dp[i][minProfit]) % MOD;
        
        return res;
    }
};

// https://tinyurl.com/rw45t3bb