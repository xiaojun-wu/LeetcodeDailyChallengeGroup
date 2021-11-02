class Solution {
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        final int MOD = 1000000000 + 7;
        int[] dp = new int[m * n];
        LinkedList<Integer> queue = new LinkedList<Integer>();
        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        
        dp[startRow * n + startColumn] = 1;
        queue.add(startRow * n + startColumn);
        
        while(queue.size() > 0 && maxMove > 0){
            int[] next = new int[m * n];
            for(int i = queue.size();i > 0;i--){
                int num = queue.poll();
                int r = num / n, c = num % n;
                for(int j = 0;j < dir.length;j++){
                    int nr = r + dir[j][0], nc = c + dir[j][1];
                    if(nr < 0 || nc < 0 || nr == m || nc == n){
                        res = (res + dp[r * n + c]) % MOD;
                    }
                    else{
                        if(next[nr * n + nc] == 0)
                            queue.add(nr * n + nc);
                        next[nr * n + nc] = (next[nr * n + nc] + dp[r * n + c]) % MOD;
                    }
                }
            }
            dp = next;
            maxMove--;
        }
        
        return res;
    }
}
// https://tinyurl.com/w75fs7k2