class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        // backtracking.
        const int SIZE = s.length();
        vector<string> res;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == SIZE){
                res.push_back(s);
                return;
            }
            if(!('0' <= s[idx] && s[idx] <= '9')){
                if(s[idx] > 'Z')
                    s[idx]-= 32;
                dfs(idx + 1);
                s[idx]+= 32;
                dfs(idx + 1);
            }
            else
                dfs(idx + 1);
        };
        
        dfs(0);
        
        return res;
    }
};
// https://tinyurl.com/yx97c7hx