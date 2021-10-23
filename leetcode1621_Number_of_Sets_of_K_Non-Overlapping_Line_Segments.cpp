class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        /*
        dp[i] means number of non-overlap segement subset that
        last segment's end point not exceed i.
        */
        vector<vector<int>> dp(n + 1,vector<int>(k + 1,0));
        for(int i = 0;i <= n;i++)
            dp[i][0] = 1;
        
        for(int i = 1;i <= k;i++){
            int presum = 0;
            for(int j = 1;j <= n;j++){
                dp[j][i] = (presum + dp[j - 1][i]) % MOD;
                presum = (presum + dp[j][i - 1]) % MOD;
            }
        }
        
        return dp[n][k];
    }
};

// https://tinyurl.com/3y57yvk4