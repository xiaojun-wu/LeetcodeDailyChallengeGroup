class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int NSIZE = nums.size(), MSIZE = multipliers.size();
        vector<vector<long long>> dp(MSIZE + 2,vector<long long>(MSIZE + 2,INT_MIN));
        const int LIMIT = min(MSIZE,NSIZE);
        dp[0][1] = nums.back() * multipliers[0];
        dp[1][0] = nums[0] * multipliers[0];
        long long res = INT_MIN;
        
        for(int i = 2;i <= LIMIT;i++){
            for(int l = 0;l <= i;l++){
                int r = i - l;
                if(l == 0)
                    dp[l][r] = dp[l][r - 1] + (long long)(nums[NSIZE - r] * multipliers[i - 1]);
                else if(r == 0)
                    dp[l][r] = dp[l - 1][r] + (long long)(nums[l - 1] * multipliers[i - 1]);
                else{
                    dp[l][r] = max(dp[l][r - 1] + (long long)(nums[NSIZE - r] * multipliers[i - 1]),dp[l - 1][r] + (long long)(nums[l - 1] * multipliers[i - 1]));
                }
            }
        }
        
        for(int i = 0;i <= LIMIT;i++)
            res = max(res,dp[i][LIMIT - i]);
        
        return res;
    }
};