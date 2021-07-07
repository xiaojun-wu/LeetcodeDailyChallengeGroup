typedef uint64_t ULL;
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int LEN = text.length();
        vector<vector<ULL>> dp(LEN,vector<ULL>(LEN,0));
        const ULL BASE = 29;
        int res = 0;
        
        for(int l = 0;l < LEN;l++){
            ULL hash = 0;
            for(int r = l;r < LEN;r++){
                hash = hash * BASE + (ULL)(text[r] - 'a' + 1);
                dp[l][r] = hash;
            }
        }
        
        for(int len = 2;len <= LEN;len+= 2){
            unordered_set<ULL> seen;
            for(int r = len - 1;r < LEN;r++){
                int l = r - len + 1;
                if(dp[l][l + len / 2 - 1] == dp[l + len / 2][r])
                    seen.insert(dp[l][r]);
            }
            res+= seen.size();
        }
        
        return res;
    }
};

// https://tinyurl.com/ym6s58a7