class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        const int MOD = 1e9 + 7;
        vector<vector<long>> dp(L + 1,vector<long>(N + 1,0));
        dp[0][0] = 1;
        
        for(int l = 1;l <= L;l++)
            for(int n = 1;n <= N;n++){
                long validUsedSong = n - K > 0?(n - K):0;
                long unuesdSond = N - n + 1;
                dp[l][n] = ((dp[l - 1][n] * validUsedSong) + (dp[l - 1][n - 1] * unuesdSond)) % MOD;
            }
        
        return dp[L][N];
    }
};

// https://tinyurl.com/3d67tvhz