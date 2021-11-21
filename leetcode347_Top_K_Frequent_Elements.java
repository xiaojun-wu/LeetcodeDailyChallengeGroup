class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        final int SIZE = nums.length;
        int res[] = new int[k];
        HashMap<Integer,Integer> map = new HashMap<>();
        int idx = 0;
        
        for(int i = 0;i < SIZE;i++)
            map.put(nums[i],map.getOrDefault(nums[i],0) + 1);
        
        int ps[][] = new int[map.size()][2];
        
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            ps[idx][0] = entry.getValue();
            ps[idx++][1] = entry.getKey();
        }
        
        Arrays.sort(ps,(a,b) -> b[0] - a[0]);
        
        for(int i = 0;i < k;i++)
            res[i] = ps[i][1];
        
        return res;
    }
}

// https://tinyurl.com/y9jz32xz