class Solution {
public:
    int longestAwesome(string s) {
        /*
        bitmask + dp, same as 1371
        TC: O(N * 10), SP: O(1024)
        */
        const int LEN = s.length();
        int counts[10] = {0};
        vector<int> dp(1 << 10,-2);
        int res = 0;
        dp[0] = -1;
        
        for(int i = 0;i < LEN;i++){
            counts[s[i] - '0']++;
            int state = 0;
            int bits = 0;
            for(int j = 0;j < 10;j++)
                if(counts[j] % 2 != 0){
                    state+= (1 << j);
                    bits++;
                }
            for(int j = 0;j < 10;j++){
                int nstate = state;
                if(state >> j & 1)
                    nstate-= (1 << j);
                else
                    nstate+= (1 << j);
                if(dp[nstate] != -2)
                    res = max(res,i - dp[nstate]);
            }
            if(dp[state] != -2)
                res = max(res,i - dp[state]);
            else
                dp[state] = i;
        }
        
        return res;
    }
};
// https://tinyurl.com/n8f53wnw