class Solution {
    public int[] minDifference(int[] nums, int[][] queries) {
        final int LEN = nums.length, QLEN = queries.length;
        int res[] = new int[QLEN];
        Arrays.fill(res,-1);
        List<List<Integer>> indice = new ArrayList<List<Integer>>();
        
        for(int i = 0;i <= 100;i++)
            indice.add(new ArrayList<Integer>());
        
        for(int i = 0;i < LEN;i++)
            indice.get(nums[i]).add(i);
        
        for(int i = 0;i < QLEN;i++){
            int left = queries[i][0], right = queries[i][1];
            int minDiff = Integer.MAX_VALUE;
            int preVal = -1;
            List<Integer> vals = new ArrayList<>();
            
            for(int j = 1;j <= 100;j++){
                int idx = lowerBound(indice.get(j),left);
                if(idx != -1 && left <= idx && idx <= right)
                    vals.add(j);
            }
            
            for(int j = 1;j < vals.size();j++)
                minDiff = Math.min(minDiff,vals.get(j) - vals.get(j - 1));
            
            if(minDiff != Integer.MAX_VALUE)
                res[i] = minDiff;
        }
        
        return res;
    }
    public int lowerBound(List<Integer> list,int target){
        int left = 0, right = list.size() - 1;
        int idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(list.get(mid) >= target){
                right = mid - 1;
                idx = list.get(mid);
            }
            else
                left = mid + 1;
        }
        return idx;
    }
}

// https://tinyurl.com/rvfefm3z