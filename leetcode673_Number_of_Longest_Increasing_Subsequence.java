class Solution {
    public int findNumberOfLIS(int[] nums) {
        final int SIZE = nums.length;
        long[] dp = new long[2001];
        int[] lens = new int[2001];
        long maxLen = 0, count = 0;
        
        for(int i = 0;i < 2001;i++){
            dp[i] = 1;
            lens[i] = 1;
        }
        
        for(int i = 0;i < SIZE;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[j] < nums[i]){
                    if(lens[j] + 1 == lens[i] && dp[i] + dp[j] <= (long)Integer.MAX_VALUE){
                        dp[i]+= dp[j];
                    }
                    if(lens[j] + 1 > lens[i]){
                        lens[i] = lens[j] + 1;
                        dp[i] = dp[j];
                    }
                }
            }
            if(lens[i] == maxLen && count + dp[i] <= (long)Integer.MAX_VALUE)
                count+= (int)dp[i];
            if(lens[i] > maxLen){
                maxLen = lens[i];
                count = (int)dp[i];
            }
        }
        
        return (int)count;
    }
}

// https://tinyurl.com/t6b35suy