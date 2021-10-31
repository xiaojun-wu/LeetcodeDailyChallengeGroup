class Solution {
    public int numberOfArrays(String s, int k) {
        final int LEN = s.length(), MOD = 1000000000 + 7, KLEN = Integer.toString(k).length();
        int[] dp = new int[LEN + 1];
        dp[0] = 1;
        
        for(int i = 0;i < LEN;i++){
            for(int j = 0;j < KLEN && i - j >= 0;j++){
                if(s.charAt(i - j) == '0')
                    continue;
                String numStr = s.substring(i - j,i + 1);
                long num = Long.parseLong(numStr);
                if(num > (long)(k))
                    break;
                dp[i + 1] = (dp[i + 1] + dp[i - j]) % MOD;
            }
        }
        
        return dp[LEN];
    }
}

// https://tinyurl.com/txy8pkze