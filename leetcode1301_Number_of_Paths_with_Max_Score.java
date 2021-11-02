class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        char[][] grid = new char[board.size()][board.get(0).length()];
        for(int i = 0;i < board.size();i++)
            grid[i] = board.get(i).toCharArray();
        final int ROW = grid.length, COL = grid[0].length, MOD = 1000000000 + 7;
        int[][] dir = {{1,0},{0,1},{1,1}};
        int[][] maxSum = new int[ROW][COL];
        int[][] dp = new int[ROW][COL];
        dp[ROW - 1][COL - 1] = 1;
        
        for(int r = ROW - 1;r >= 0;r--){
            for(int c = COL - 1;c >= 0;c--){
                if(grid[r][c] == 'X' || grid[r][c] == 'S')
                    continue;
                int val = grid[r][c] == 'E'?0:grid[r][c] - '0';
                boolean isReach = false;
                
                for(int i = 0;i < dir.length;i++){
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if(nr == ROW || nc == COL || grid[nr][nc] == 'X')
                        continue;
                    isReach = true;
                    if(maxSum[nr][nc] + val == maxSum[r][c])
                        dp[r][c] = (dp[r][c] + dp[nr][nc]) % MOD;
                    else if(maxSum[nr][nc] + val > maxSum[r][c]){
                        maxSum[r][c] = maxSum[nr][nc] + val;
                        dp[r][c] = dp[nr][nc];
                    }
                }
                
                if(!isReach){
                    grid[r][c] = 'X';
                }
            }
        }
        
        return new int[]{maxSum[0][0],dp[0][0]};
    }
}

// https://tinyurl.com/h7zukv94