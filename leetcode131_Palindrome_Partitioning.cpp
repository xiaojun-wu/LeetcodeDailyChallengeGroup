class Solution {
public:
    vector<vector<string>> partition(string s) {
        /*
        if(s[i:j] is palindrome, check if we can split s[j + 1:end] to make each substring of that also palindorme)
        */
        const int LEN = s.length();
        vector<vector<string>> res;
        vector<string> cur;
        vector<vector<bool>> isPalindrome(LEN,vector<bool>(LEN,false));
        
        for(int l = 1;l <= LEN;l++)
            for(int i = 0;i + l <= LEN;i++)
                if(s[i] == s[i + l - 1])
                    if(l < 3 || isPalindrome[i + 1][i + l - 2])
                        isPalindrome[i][i + l - 1] = true;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == LEN){
                res.push_back(cur);
                return;
            }
            string palin = "";
            for(int i = idx;i < LEN;i++){
                palin+= s[i];
                if(isPalindrome[idx][i]){
                    cur.push_back(palin);
                    dfs(i + 1);
                    cur.pop_back();
                }
            }
        };
        
        dfs(0);
        
        return res;
    }
};
// https://tinyurl.com/4nahwaff