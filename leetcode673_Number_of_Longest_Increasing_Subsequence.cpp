class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int SIZE = nums.size();
        long maxLen = 0, count = 0;
        vector<long> dp(SIZE + 1,1);
        vector<int> len(SIZE,1);
        dp[0] = 1;

        for(int i = 0;i < SIZE;i++)
            for(int j = i - 1;j >= 0;j--)
                if(nums[i] > nums[j]){
                    if(len[j] >= len[i]){
                        dp[i] = dp[j];
                        len[i] = len[j] + 1;
                    }
                    else if(len[j] + 1 == len[i] && dp[i] + dp[j] <= INT_MAX)
                        dp[i]+= dp[j];
                }

        for(int i = 0;i < SIZE;i++){
            if(maxLen < len[i]){
                maxLen = len[i];
                count = dp[i];
            }
            else if(maxLen == len[i] && count + dp[i] <= INT_MAX)
                count+= dp[i];
        }

        return count;
    }
};

// https://tinyurl.com/t6b35suy