class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const int LEN = digits.length();
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string cur = "";
        
        if(LEN == 0)
            return res;
        
        function<void()> dfs = [&]() {
            if(cur.length() == LEN)
                return res.push_back(cur);
            for(char c : mp[digits[cur.length()] - '0']){
                cur+= c;
                dfs();
                cur.pop_back();
            }
        };
        
        dfs();
        
        return res;
    }
};
// https://tinyurl.com/xmdvaczk