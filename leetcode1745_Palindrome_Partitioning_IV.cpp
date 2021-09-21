class Solution {
public:
    bool checkPartitioning(string s) {
        const int LEN = s.length();
        vector<vector<int>> dp(LEN,vector<int>(LEN,0));
        
        for(int len = 1;len <= LEN;len++)
            for(int l = 0;l + len <= LEN;l++){
                int r = l + len - 1;
                if(s[l] == s[r]){
                    if(r - l < 2)
                        dp[l][r] = 1;
                    else if(dp[l + 1][r - 1])
                        dp[l][r] = 1;
                }
            }
        
        for(int l = 1;l < LEN - 1;l++)
            for(int r = l;r < LEN - 1;r++)
                if(dp[0][l - 1] && dp[l][r] && dp[r + 1][LEN - 1])
                    return true;
        
        return false;
    }
};
