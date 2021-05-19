class Solution {
public:
    int constrainedSubsetSum(vector<int>& dp, int k) {
        /*
        dp? dp[j] means maximum of subsequence end with nums[i].
        dp[j] = max(dp[j],dp[i] + nums[j]) for j - i <= k.
        the basic dp solution is O(N^2), it will be TLE for this problem.
        We can use sliding windows and monotomic stack to keep tracking
        the largest dp[i].
        */
        const int SIZE = dp.size();
        deque<int> q;
        int res = INT_MIN;
        
        for(int i = 0;i < SIZE;i++){
            if(!q.empty() && dp[q.front()] > 0)
                dp[i]+= dp[q.front()];
            while(!q.empty() && dp[q.back()] < dp[i])
                q.pop_back();
            q.push_back(i);
            if(i - k == q.front())
                q.pop_front();
            res = max(res,dp[i]);
        }
        
        return res;
    }
};