class Solution {
    public int[][] kClosest(int[][] points, int k) {
        final int SIZE = points.length;
        int dis[][] = new int[SIZE][2];
        int res[][] = new int[k][2];
        
        for(int i = 0;i < SIZE;i++){
            dis[i][0] = (int)Math.pow(points[i][0],2) + (int)Math.pow(points[i][1],2);
            dis[i][1] = i;
        }
        
        Arrays.sort(dis,(a,b) -> a[0] - b[0]);
        
        for(int i = 0;i < k;i++)
            res[i] = points[dis[i][1]];
        
        return res;
    }
}