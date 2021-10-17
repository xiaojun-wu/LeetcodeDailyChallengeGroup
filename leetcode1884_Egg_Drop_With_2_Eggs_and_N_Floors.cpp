class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1,n);
        dp[0] = dp[1] = 1;
        
        for(int i = 2;i <= n;i++)
            for(int j = i - 1;j >= 1;j--)
                dp[i] = min(dp[i],max(j,dp[i - j] + 1));
        return dp[n];
    }
};
/*
if we choose first drop if m:
1. If egg break in m floor, we have to do up to m - 1 more drops, total m drops needs.
2. If egg wasn't break, we can image m floor is 0, and n is n - m floor, start this process over by determine a egg in n - m floors + 1.

DP: TC : O(N^2), SC : O(N)
*/

// https://tinyurl.com/ua9e4zew