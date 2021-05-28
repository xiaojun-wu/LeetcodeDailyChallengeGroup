class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // two pointers.
        const int SIZE = nums.size();
        int res = SIZE + 1, sum = 0;
        
        for(int l = 0,r = 0;r < SIZE;r++){
            sum+= nums[r];
            while(sum >= target){
                res = min(res,r - l + 1);
                sum-= nums[l++];
            }
        }
        
        return res == SIZE + 1?0:res;
    }
};