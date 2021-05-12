class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // backtracking + dp.
        const int LEN = s.length();
        vector<string> res;
        vector<bool> dp(LEN + 1,false);
        vector<vector<string>> record(LEN,vector<string>());
        unordered_set<string> exist(wordDict.begin(),wordDict.end());
        dp[LEN] = true;
        
        for(int i = LEN - 1;i >= 0;i--){
            string cur = "";
            for(int j = i;j < LEN;j++){
                cur+= s[j];
                if(dp[j + 1] && exist.count(cur)){
                    record[i].push_back(cur);
                    dp[i] = true;
                }
            }
        }
        
        function<void(int,string)> dfs = [&](int idx,string cur) {
            if(idx == LEN){
                cur.pop_back();
                return res.push_back(cur);
            }
            for(string word : record[idx])
                dfs(idx + word.length(),cur + word + ' ');
        };
        
        dfs(0,"");
        
        return res;
    }
};
// https://tinyurl.com/rbvxwmwc