class Solution {
    public int minSpaceWastedKResizing(int[] nums, int k) {
        final int SIZE = nums.length, MAXTIME = 1000000 * 200 + 1;
        int[][] dp = new int[SIZE + 1][k + 2];
        
        for(int i = 0;i <= SIZE;i++)
            for(int j = 0;j <= k + 1;j++)
                dp[i][j] = MAXTIME;
        
        for(int i = 0;i <= k;i++)
            dp[SIZE][i] = 0;
        
        for(int i = SIZE - 1;i >= 0;i--){
            for(int j = k + 1;j >= 0;j--){
                int maxHeight = nums[i];
                int area = 0;
                for(int l = i;l < SIZE;l++){
                    maxHeight = Math.max(maxHeight,nums[l]);
                    area+= nums[l];
                    int waste = (l - i + 1) * maxHeight - area;
                    if(j > 0)
                        dp[i][j] = Math.min(dp[i][j],waste + dp[l + 1][j - 1]);
                }
            }
        }
        
        return dp[0][k + 1];
    }
}