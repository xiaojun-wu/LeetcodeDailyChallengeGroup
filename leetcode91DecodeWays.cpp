class Solution {
public:
    int numDecodings(string s) {
        const int LEN = s.length();
        int dp[3] = {0};
        dp[2] = 1;
        if(s.back() != '0') dp[1] = 1;

        for(int i = LEN - 2;i >= 0;i--){
            if(s[i] != '0' && s[i + 1] != '0') dp[0]+= dp[1];
            if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) dp[0]+= dp[2];
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = 0;
        }

        return dp[1];
    }
};