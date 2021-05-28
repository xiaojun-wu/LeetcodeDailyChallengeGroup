class Solution {
public:
    int longestSubstring(string s, int k) {
        const int SLEN = s.length(), KLEN = k;
        if(KLEN > SLEN)
            return 0;
        vector<vector<int>> preCounts;
        vector<int> counts(26,0);
        vector<int> lastOccur(26,-1);
        int res = 0;
        
        for(int i = 0;i < SLEN;i++){
            counts[s[i] - 'a']++;
            preCounts.push_back(counts);
            lastOccur[s[i] - 'a'] = i;
            int lastIdx = -1;
            for(int j = 0;j < 26;j++)
                if(counts[j] < k)
                    lastIdx = max(lastIdx,lastOccur[j]);
            if(lastIdx == -1)
                res = max(res,i + 1);
            else{
                bool isValid = true;
                for(int j = 0;j < 26 && isValid;j++)
                    if(counts[j] - preCounts[lastIdx][j] != 0 && counts[j] - preCounts[lastIdx][j] < k)
                        isValid = false;
                if(isValid)
                    res = max(res,i - lastIdx);
            }
        }
        
        return res;
    }
};