class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if((totalSum - target) % 2 != 0)
            return false;
        int size = (totalSum - target) / 2;
        vector<int> dp(size + 1,0);
        dp[0] = 1;
        
        for(int n : nums)
            for(int i = size - n;i >= 0;i--)
                if(dp[i])
                    dp[i + n]+= dp[i];
        
        return dp[size];
    }
};
