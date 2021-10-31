class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        final int SIZE = scores.length;
        int[][] list = new int[SIZE][2];
        int[] dp = new int[SIZE];
        int res = 0;
        
        for(int i = 0;i < SIZE;i++){
            list[i][0] = ages[i];
            list[i][1] = scores[i];
        }
        
        Arrays.sort(list,(a,b) -> a[0] == b[0]?a[1] - b[1] : a[0] - b[0]);
        
        for(int i = 0;i < SIZE;i++){
            int curScore = list[i][1];
            int curAge = list[i][0];
            dp[i] = curScore;
            for(int j = i - 1;j >= 0;j--){
                int preScore = list[j][1];
                int preAge = list[j][0];
                if(preScore <= curScore)
                    dp[i] = Math.max(dp[i],dp[j] + curScore);
            }
            res = Math.max(res,dp[i]);
        }
        
        return res;
    }
}