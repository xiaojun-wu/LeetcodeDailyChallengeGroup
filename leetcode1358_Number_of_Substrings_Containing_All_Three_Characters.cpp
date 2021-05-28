class Solution {
public:
    int numberOfSubstrings(string s) {
        const int LEN = s.length();
        vector<int> lastIdx(3,-1);
        int res = 0;
        
        for(int i = 0;i < LEN;i++){
            lastIdx[s[i] - 'a'] = i;
            int minIdx = i;
            for(int n : lastIdx)
                minIdx = min(minIdx,n);
            if(minIdx == -1) continue;
            res+= minIdx + 1;
        }
        
        return res;
    }
};