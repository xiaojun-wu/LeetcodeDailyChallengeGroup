class Solution {
public:
    int longestValidParentheses(string s) {
        // dp
        const int LEN = s.length();
        vector<int> dp(LEN + 1,-1);
        int res = 0;
        
        function<int(int)> getPrevious = [&](int idx) ->int {
            if(idx < 0 || dp[idx] == -1)
                return 0;
            return dp[idx];
        };
        
        for(int i = 0;i < LEN;i++){
            if(s[i] == ')' && i > 0){
                if(s[i - 1] == '('){
                    dp[i] = 2;
                    dp[i]+= getPrevious(i - 2);
                }
                else if(dp[i - 1] != -1){
                    if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = dp[i - 1] + 2 + getPrevious(i - dp[i - 1] - 2);
                }
            }
            res = max(res,dp[i]);
        }
        
        return res;
    }
};