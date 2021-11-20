class Solution {
    public int rearrangeSticks(int n, int k) {
        final int MOD = 1000000000 + 7;
        long dp[] = new long[k + 1];
        dp[0] = 1;
        
        for(int i = 1;i <= n;i++){
            long next[] = new long[k + 1];
            for(int j = Math.min(k,i);j >= 1;j--)
                next[j] = (dp[j - 1] + dp[j] * (i - 1)) % MOD;
            dp = next;
        }
        
        return (int)dp[k];
    }
}
