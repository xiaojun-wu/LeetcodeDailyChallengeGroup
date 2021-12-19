class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int SIZE = nums.length;
        int res[] = new int[SIZE];
        Stack<Integer> stack = new Stack<>();
        
        for(int i = SIZE - 1;i >= 0;i--){
            while(!stack.empty() && stack.peek() <= nums[i])
                stack.pop();
            if(!stack.empty())
                res[i] = stack.peek();
            else
                res[i] = Integer.MIN_VALUE;
            stack.push(nums[i]);
        }
        
        for(int i = SIZE - 1;i >= 0;i--){
            while(!stack.empty() && stack.peek() <= nums[i])
                stack.pop();
            if(!stack.empty() && res[i] == Integer.MIN_VALUE && stack.peek() > nums[i])
                res[i] = stack.peek();
            if(res[i] == Integer.MIN_VALUE)
                res[i] = -1;
        }
        
        return res;
    }
}

// https://tinyurl.com/3k28zbfa