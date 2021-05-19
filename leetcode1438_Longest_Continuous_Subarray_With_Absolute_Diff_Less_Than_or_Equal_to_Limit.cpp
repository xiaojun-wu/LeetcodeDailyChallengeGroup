class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int SIZE = nums.size();
        deque<int> minStack, maxStack;
        int res = 1;
        
        for(int i = 0, j = 0;i < SIZE;i++){
            while(!minStack.empty() && nums[minStack.back()] > nums[i])
                minStack.pop_back();
            while(!maxStack.empty() && nums[maxStack.back()] < nums[i])
                maxStack.pop_back();
            minStack.push_back(i);
            maxStack.push_back(i);
            while(j < i && nums[maxStack.front()] - nums[minStack.front()] > limit){
                while(!maxStack.empty() && maxStack.front() <= j)
                    maxStack.pop_front();
                while(!minStack.empty() && minStack.front() <= j)
                    minStack.pop_front();
                j++;
            }
            res = max(res,i - j + 1);
        }
        
        return res;
    }
};
// https://tinyurl.com/p4ar6dxk