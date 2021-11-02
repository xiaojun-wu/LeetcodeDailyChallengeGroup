class Solution {
    public int minFallingPathSum(int[][] matrix) {
        final int ROW = matrix.length, COL = matrix[0].length;
        int res = Integer.MAX_VALUE;
        
        for(int r = 1;r < ROW;r++){
            for(int c = 0;c < COL;c++){
                int val = matrix[r][c];
                matrix[r][c] = val + matrix[r - 1][c];
                if(c - 1 >= 0)
                    matrix[r][c] = Math.min(matrix[r][c],val + matrix[r - 1][c - 1]);
                if(c + 1 < COL)
                    matrix[r][c] = Math.min(matrix[r][c],val + matrix[r - 1][c + 1]);
            }
        }
        
        return Arrays.stream(matrix[ROW - 1]).min().getAsInt();
    }
}

// https://tinyurl.com/yrb6knp3