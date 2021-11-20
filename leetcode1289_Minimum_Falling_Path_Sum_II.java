class Solution {
    public int minFallingPathSum(int[][] grid) {
        final int SIZE = grid.length;
        if(SIZE == 1)
            return grid[0][0];
        int min1 = 0, min2 = 0, idx = -1;
        
        for(int r = 0;r < SIZE;r++){
            int curmin1 = 200000;
            int curmin2 = 200000;
            int curidx = -1;
            for(int c = 0;c < SIZE;c++){
                int cur = 200000;
                if(c == idx){
                    cur = grid[r][c] + min2;
                }
                else
                    cur = grid[r][c] + min1;
                if(cur < curmin1){
                    curmin2 = curmin1;
                    curmin1 = cur;
                    curidx = c;
                }
                else if(cur < curmin2)
                    curmin2 = cur;
            }
            min1 = curmin1;
            min2 = curmin2;
            idx = curidx;
        }
        
        return min1;
    }
}

// https://tinyurl.com/sdrerpzm