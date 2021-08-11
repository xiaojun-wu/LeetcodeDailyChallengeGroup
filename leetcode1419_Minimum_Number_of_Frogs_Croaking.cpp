class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        const int LEN = croakOfFrogs.length();
        string s = "croak";
        int mp[26] = {0}, dp[5] = {0};
        mp['c' - 'a'] = 0;
        mp['r' - 'a'] = 1;
        mp['o' - 'a'] = 2;
        mp['a' - 'a'] = 3;
        mp['k' - 'a'] = 4;
        int res = 0, offset = 0;
        
        for(char c : croakOfFrogs){
            int idx = mp[c - 'a'];
            dp[idx]++;
            if(idx != 0 && dp[idx - 1] < dp[idx])
                return -1;
            if(idx == 4)
                offset++;
            res = max(res,dp[idx] - offset);
        }
        
        if(accumulate(dp,dp + 5,0) != offset * 5)
            return -1;
        
        return res;
    }
};