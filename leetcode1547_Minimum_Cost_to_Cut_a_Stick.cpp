class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        const int SIZE = cuts.size();
        vector<vector<int>> dp(SIZE,vector<int>(SIZE,1e9));
        sort(cuts.begin(),cuts.end());
        
        for(int i = 0;i < SIZE - 1;i++)
            dp[i][i + 1] = 0;
        
        for(int len = 3;len <= SIZE;len++){
            for(int l = 0;l + len <= SIZE;l++){
                int r = l + len - 1;
                for(int i = l + 1;i < r;i++){
                    dp[l][r] = min(dp[l][r],dp[l][i] + dp[i][r] + cuts[r] - cuts[l]);
                }
            }
        }
        
        return dp[0][SIZE - 1];
    }
};
