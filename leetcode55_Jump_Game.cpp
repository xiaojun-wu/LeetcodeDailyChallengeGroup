class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int SIZE = nums.size();
        int rightMost = 0;
        
        for(int i = 0;i <= rightMost;i++){
            rightMost = max(rightMost,i + nums[i]);
            if(rightMost >= SIZE - 1) return true;
        }
        
        return false;
    }
};