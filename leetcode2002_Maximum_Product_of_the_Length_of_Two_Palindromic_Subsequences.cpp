class Solution {
public:
    int maxProduct(string s) {
        const int LEN = s.length(), TOTAL = 1 << LEN;
        int res = 0;
        vector<int> valid;
        
        function<bool(string&)> isPalindromic = [&](string& str) ->bool {
            int left = 0, right = str.length() - 1;
            while(left < right)
                if(str[left++] != str[right--])
                    return false;
            return true;
        };
        
        for(int i = 1;i < TOTAL;i++){
            string word = "";
            for(int j = LEN - 1;j >= 0;j--)
                if(((i >> j) & 1) == 1)
                    word+= s[LEN - j - 1];
            if(isPalindromic(word))
                valid.push_back(i);
        }
        
        for(int i = 0;i < valid.size();i++)
            for(int j = i + 1;j < valid.size();j++){
                if((valid[i] & valid[j]) > 0)
                    continue;
                res = max(res,(int)(bitset<13>(valid[i]).count() * bitset<13>(valid[j]).count()));
                if(res == 36)
                    break;
            }
        
        return res;
    }
};

// https://tinyurl.com/4ucsje5c