class Solution {
    public int cherryPickup(int[][] grid) {
        final int ROW = grid.length, COL = grid[0].length;
        int[] dir = new int[]{-1,0,1};
        int[][] dp = new int[COL][COL];
        int res = 0;
        
        for(int[] c : dp)
            Arrays.fill(c,-1);
        
        dp[0][COL - 1] = grid[0][0] + grid[0][COL - 1];
        
        for(int r = 0;r < ROW - 1;r++){
            int[][] next = new int[COL][COL];
            for(int[] c : next)
                Arrays.fill(c,-1);
            for(int c1 = 0;c1 < COL;c1++){
                for(int c2 = 0;c2 < COL;c2++){
                    if(dp[c1][c2] == -1)
                        continue;
                    int preval = dp[c1][c2];
                    for(int i = 0;i < dir.length;i++)
                        for(int j = 0;j < dir.length;j++){
                            int nc1 = c1 + dir[i], nc2 = c2 + dir[j];
                            if(nc1 < 0 || nc2 < 0 || nc1 == COL || nc2 == COL)
                                continue;
                            int val = grid[r + 1][nc1];
                            if(nc1 != nc2)
                                val+= grid[r + 1][nc2];
                            next[nc1][nc2] = Math.max(next[nc1][nc2],preval + val);
                        }
                }
            }
            dp = next;
        }
        
        for(int c1 = 0;c1 < COL;c1++)
            for(int c2 = 0;c2 < COL;c2++)
                res = Math.max(res,dp[c1][c2]);
        
        return res;
    }
}