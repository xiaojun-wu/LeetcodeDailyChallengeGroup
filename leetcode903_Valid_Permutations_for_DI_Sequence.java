class Solution {
    public int numPermsDISequence(String s) {
        final int LEN = s.length(), MOD = 1000000000 + 7;
        int dp[] = {1,0};
        int res = 0;
        
        for(int i = 1;i <= LEN;i++){
            int next[] = new int[i + 2];
            if(s.charAt(i - 1) == 'D')
                for(int j = i;j >= 0;j--)
                    next[j] = (next[j + 1] + dp[j])% MOD;
            else
                for(int j = 1;j <= i;j++)
                    next[j] = (next[j - 1] + dp[j - 1]) % MOD;
            dp = next;
        }
        
        for(int i = 0;i <= LEN;i++)
            res = (res + dp[i]) % MOD;
        
        return res;
    }
}
/*
if(s[i] == 'I') // increase
dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... dp[i - 1][0];
dp[i][j + 1] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... dp[i - 1][0];

so dp[i][j + 1] = dp[i][j] + dp[i - 1][j];
*/