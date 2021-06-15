class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        /*
        decreasing monotonic stack, two pass
        TC:O(N), SC: O(N).
        */
        const int SIZE = nums.size();
        vector<int> stack;
        int res = 0;
        
        for(int i = 0;i < SIZE;i++)
            if(stack.empty() || nums[stack.back()] > nums[i])
                stack.push_back(i);
        
        for(int i = SIZE - 1;i >= 0 && !stack.empty();i--){
            while(!stack.empty() && nums[stack.back()] <= nums[i]){
                res = max(res,i - stack.back());
                stack.pop_back();
            }
        }
        
        return res;
    }
};