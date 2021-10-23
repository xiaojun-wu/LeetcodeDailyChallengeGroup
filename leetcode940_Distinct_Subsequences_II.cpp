class Solution {
public:
    int distinctSubseqII(string S) {
        const int LEN = S.length(), MOD = 1e9 + 7;
        int presum[2001] = {0};
        int mp[26] = {0};
        
        for(int i = 0;i < LEN;i++){
            int cur = 0;
            char c = S[i];
            if(mp[c - 'a'] == 0)
                cur++;
            int pre = 0;
            if(mp[c -  'a'] > 1)
                pre = presum[mp[c -  'a'] - 1];
            presum[i + 1] = (cur + (presum[i] * 2) % MOD + MOD - pre) % MOD;
            mp[c - 'a'] = i + 1;
        }
        
        return presum[LEN];
    }
};

// https://tinyurl.com/d7jusaz3