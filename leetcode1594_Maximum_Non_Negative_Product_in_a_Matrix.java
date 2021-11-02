class Solution {
    public int maxProductPath(int[][] grid) {
        final int ROW = grid.length, COL = grid[0].length, MOD = 1000000000 + 7;
        long[][][] dp = new long[ROW][COL][2];
        dp[0][0][0] = (long)(grid[0][0]);
        dp[0][0][1] = (long)(grid[0][0]);
        
        for(int r = 0;r < ROW;r++){
            for(int c = 0;c < COL;c++){
                if(r != 0 || c != 0){
                    dp[r][c][0] = Long.MAX_VALUE;
                    dp[r][c][1] = Long.MIN_VALUE;
                }
                long val = (long)grid[r][c];
                if(r - 1 >= 0){
                    long val1 = val * dp[r - 1][c][0], val2 = val * dp[r - 1][c][1];
                    dp[r][c][0] = Math.min(dp[r][c][0],Math.min(val1,val2));
                    dp[r][c][1] = Math.max(dp[r][c][1],Math.max(val1,val2));
                }
                if(c - 1 >= 0){
                    long val1 = val * dp[r][c - 1][0], val2 = val * dp[r][c - 1][1];
                    dp[r][c][0] = Math.min(dp[r][c][0],Math.min(val1,val2));
                    dp[r][c][1] = Math.max(dp[r][c][1],Math.max(val1,val2));
                }
            }
        }
        
        return dp[ROW - 1][COL - 1][1] < 0?-1:(int)(dp[ROW - 1][COL - 1][1] % MOD);
    }
}

// https://tinyurl.com/4nanz7mv