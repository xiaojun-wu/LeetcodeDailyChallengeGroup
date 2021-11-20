class Solution {
    public int kInversePairs(int n, int k) {
        final int MOD = 1000000000 + 7;
        long dp[] = new long[k + 1];
        long presum[] = new long[k + 1];
        Arrays.fill(presum,1);
        dp[0] = 1;
        
        for(int len = 1;len <= n;len++){
            int limit = Math.min((len * (len - 1) / 2),k);
            for(int i = 1;i <= limit;i++){
                long pre = 0;
                if(i - len >= 0)
                    pre = presum[i - len];
                dp[i] = (presum[i] - pre + MOD) % MOD;
            }
            for(int i = 1;i <= k;i++)
                presum[i] = (presum[i - 1] + dp[i]) % MOD;
        }
        
        return (int)dp[k];
    }
}