class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int SIZE = nums.size(), OFFSET = 500;
        int dp[1001][1002] = {0};
        int maxLen = 0;
        
        for(int i = 0;i < SIZE;i++){
            for(int j = i - 1;j >= 0;j--){
                int diff = nums[i] - nums[j] + OFFSET;
                int val = dp[j][diff] == 0?1:dp[j][diff];
                dp[i][diff] = max(dp[i][diff],val + 1);
                maxLen = max(maxLen,dp[i][diff]);
            }
        }
        
        return maxLen;
    }
};