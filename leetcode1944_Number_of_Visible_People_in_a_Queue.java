class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int SIZE = heights.length;
        Stack<Integer> stack = new Stack<>();
        int res[] = new int[SIZE];
        
        for(int i = SIZE - 1;i >= 0;i--){
            while(!stack.empty() && stack.peek() < heights[i]){
                res[i]++;
                stack.pop();
            }
            if(!stack.empty())
                res[i]++;
            stack.push(heights[i]);
        }
        
        return res;
    }
}

// https://tinyurl.com/bdhtye4a