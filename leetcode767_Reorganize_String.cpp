class Solution {
public:
    string reorganizeString(string s) {
        const int LEN = s.length();
        if(LEN == 1)
            return s;
        int count[26] = {0};
        int maxFreq = 0;
        string res = string(LEN,' ');
        
        for(char c : s)
            maxFreq = max(maxFreq,++count[c - 'a']);
        
        if(maxFreq > (LEN + 1) / 2)
            return "";
        
        sort(s.begin(),s.end(),[&](char& lhs,char& rhs){
            if(count[lhs - 'a'] != count[rhs - 'a'])
                return count[lhs - 'a'] > count[rhs - 'a'];
            return lhs < rhs;
        });
        int idx = 0;
        
        for(int i = 0;i < LEN;i+= 2)
            res[i] = s[idx++];
        for(int i = 1;i < LEN;i+= 2)
            res[i] = s[idx++];
        
        return res;
    }
};