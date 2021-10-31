class Solution {
    public int maxHeight(int[][] cuboids) {
        final int SIZE = cuboids.length, MOD = 1000000000 + 7;
        int[] dp = new int[SIZE];
        int res = 0;
        
        for(int i = 0;i < SIZE;i++)
            Arrays.sort(cuboids[i]);
        
        Arrays.sort(cuboids,(a,b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            if(a[1] != b[1])
                return a[1] - b[1];
            return a[2] - b[2];
        });
        
        for(int i = 0;i < SIZE;i++){
            dp[i] = cuboids[i][2];
            for(int j = i - 1;j >= 0;j--){
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                    dp[i] = Math.max(dp[i],dp[j] + cuboids[i][2]);
                }
            }
            res = Math.max(res,dp[i]);
        }
        
        return res;
    }
}