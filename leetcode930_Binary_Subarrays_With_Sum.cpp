class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // dp, TC: O(N), SC: O(N)
        const int SIZE = nums.size();
        vector<int> dp(SIZE + 1,0);
        dp[0] = 1;
        int presum = 0, res = 0;
        
        for(int n : nums){
            presum+= n;
            if(presum >= goal)
                res+= dp[presum - goal];
            dp[presum]++;
        }
        
        return res;
    }
};
// https://tinyurl.com/2x6v9k4z