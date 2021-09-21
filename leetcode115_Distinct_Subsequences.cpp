class Solution {
public:
    int numDistinct(string s, string t) {
        const int SLEN = s.length(), TLEN = t.length();
        vector<long> dp(TLEN + 1,0);
        vector<vector<int>> pos(58,vector<int>());
        dp[0] = 1;
        
        for(int i = TLEN - 1;i >= 0;i--)
            pos[t[i] - 'A'].push_back(i);
        
        for(int i = 0;i < SLEN;i++)
            for(int p : pos[s[i] - 'A'])
                if(dp[p + 1] + dp[p] <= INT_MAX)
                    dp[p + 1]+= dp[p];
        
        return dp.back();
    }
};