class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int SIZE = s.length();
        vector<int> pos(256,-1);
        int res = 0;
        
        for(int r = 0,l = 0;r < SIZE;r++){
            if(pos[s[r]] >= l)
                l = pos[s[r]] + 1;
            pos[s[r]] = r;
            res = max(res,r - l + 1);
        }
        
        return res;
    }
};
// https://tinyurl.com/ksj4c6et