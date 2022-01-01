class Solution {
    public int maxCoins(int[] nums) {
        int SIZE = nums.length;
        int arr[] = new int[SIZE + 2];
        arr[0] = arr[SIZE + 1] = 1;
        for(int i = 0;i < SIZE;i++)
            arr[i + 1] = nums[i];
        int dp[][] = new int[SIZE + 2][SIZE + 2];
        
        for(int len = 3;len <= SIZE + 2;len++){
            for(int left = 0;left + len <= SIZE + 2;left++){
                int right = left + len - 1;
                for(int i = left + 1;i < right;i++){
                    dp[left][right] = Math.max(dp[left][right],arr[left] * arr[right] * arr[i] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][SIZE + 1];
    }
}

// https://tinyurl.com/yckjaud8