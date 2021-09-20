class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int SIZE = stones.size();
        int dp[1001][1001] = {0};
        int presum[1001] = {0};
        
        for(int i = 0;i < SIZE;i++)
            presum[i + 1] = presum[i] + stones[i];
        
        for(int len = 2;len <= SIZE;len++){
            for(int l = 0;l + len <= SIZE;l++){
                int r = l + len - 1;
                dp[l][r] = max(presum[r + 1] - presum[l + 1] - dp[l + 1][r],presum[r] - presum[l] - dp[l][r - 1]);
            }
        }
        
        return dp[0][SIZE - 1];
    }
};