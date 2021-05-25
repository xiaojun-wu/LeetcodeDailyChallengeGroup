class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /*
        find longest subarray with sum equals to sum(nums) - x.
        */
        const int SIZE = nums.size();
        int res = -1;
        int totalsum = accumulate(nums.begin(),nums.end(),0), cursum = 0;
        int target = totalsum - x;
        if(target < 0)
            return -1;
        
        for(int l = 0,r = 0;r < SIZE;r++){
            cursum+= nums[r];
            while(cursum > target)
                cursum-= nums[l++];
            if(cursum == target)
                res = max(res,r - l + 1);
        }
        
        return res == -1?-1:SIZE - res;
    }
};
// https://tinyurl.com/wj6cwev9