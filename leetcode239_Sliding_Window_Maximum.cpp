class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        vector<int> res;
        deque<int> stack;
        
        for(int i = 0;i < k - 1;i++){
            while(!stack.empty() && nums[stack.back()] < nums[i])
                stack.pop_back();
            stack.push_back(i);
        }
        
        for(int i = k - 1;i < SIZE;i++){
            while(!stack.empty() && nums[stack.back()] < nums[i])
                stack.pop_back();
            stack.push_back(i);
            res.push_back(nums[stack.front()]);
            if(stack.front() == i - k + 1)
                stack.pop_front();
        }
        
        return res;
    }
};