class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int SIZE = nums.size(), MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        vector<int> dp(SIZE + 1,1);
        int left = 0,right = SIZE - 1,res = 0;
        
        for(int i = 1;i <= SIZE;i++)
            dp[i] = (dp[i - 1] * 2) % MOD;
        
        while(left <= right){
            if(nums[left] + nums[right] > target) right--;
            else
                res = (res + dp[right - left++]) % MOD;
        }
        
        return res;
    }
};
// 