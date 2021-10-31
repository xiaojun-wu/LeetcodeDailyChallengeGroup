class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        final int SIZE = nums.length;
        Map<Integer,Integer> map = new HashMap<>();
        int left = -1, res = 0;
        map.put(0,-1);
        
        for(int i = 0, sum = 0;i < SIZE;i++){
            sum+= nums[i];
            int idx = map.getOrDefault(sum - target,-2);
            if(idx >= left){
                res++;
                left = i;
            }
            map.put(sum,i);
        }
        
        return res;
    }
}

// https://tinyurl.com/y5symt6w