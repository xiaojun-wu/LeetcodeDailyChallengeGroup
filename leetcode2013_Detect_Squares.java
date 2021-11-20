class DetectSquares {
    private HashMap<Integer,Integer> map;
    public DetectSquares() {
        map = new HashMap<Integer,Integer>();
    }
    
    public void add(int[] point) {
        int val = point[0] * 10000 + point[1];
        map.put(val,map.getOrDefault(val,0) + 1);
    }
    
    public int count(int[] point) {
        int x = point[0], y = point[1];
        int res = 0;
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            int key = entry.getKey(), count = entry.getValue();
            int x1 = key / 10000, y1= key % 10000, len = (int)Math.abs(y1 - y);
            if(x1 != x || len == 0)
                continue;
            int point1 = (x - len) * 10000 + y;
            int point2 = (x - len) * 10000 + y1;
            int point3 = (x + len) * 10000 + y;
            int point4 = (x + len) * 10000 + y1;
            
            res+= map.getOrDefault(point1,0) * map.getOrDefault(point2,0) * count;
            res+= map.getOrDefault(point3,0) * map.getOrDefault(point4,0) * count;
        }
        return res;
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */

 // https://tinyurl.com/3e669wx4