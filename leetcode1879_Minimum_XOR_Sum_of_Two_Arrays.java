class Solution {
    private int dp[];
    public int minimumXORSum(int[] nums1, int[] nums2) {
        final int N = nums1.length, TOTALSTATES = 1 << N;
        dp = new int[TOTALSTATES];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int state = 1;state < TOTALSTATES;state++){
            for(int i = 0;i < N;i++){
                if((state & (1 << i)) > 0){
                    dp[state] = Math.min(dp[state],dp[state - (1 << i)] + (nums2[i] ^ nums1[Integer.bitCount(state) - 1]));
                }
            }
        }
        
        return dp[TOTALSTATES - 1];
    }
}