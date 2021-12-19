class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        int res[] = new int[nums1.length];
        
        for(int i = 0;i < nums1.length;i++)
            map.put(nums1[i],i);
        
        for(int i = nums2.length - 1;i >= 0;i--){
            while(!stack.empty() && stack.peek() < nums2[i])
                stack.pop();
            if(map.containsKey(nums2[i])){
                if(!stack.empty())
                    res[map.get(nums2[i])] = stack.peek();
                else
                    res[map.get(nums2[i])] = -1;
            }
            stack.push(nums2[i]);
        }
        
        return res;
    }
}

// https://tinyurl.com/mthd64