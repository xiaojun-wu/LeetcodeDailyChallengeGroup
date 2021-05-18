class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        // brute force + dp
        const int SIZE = s.length();
        vector<vector<vector<int>>> dp(SIZE,vector<vector<int>>(SIZE,vector<int>()));
        
        function<int(char,int,int)> calculator = [&](char exp,int l,int r) ->int {
            if(exp == '+')
                return l + r;
            else if(exp == '-')
                return l - r;
            return l * r;
        };
        
        function<void(int,int)> dfs = [&](int l,int r) {
            if(dp[l][r].size() > 0)
                return;
            for(int i = l + 1;i < r;i++){
                if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                    if(dp[l][i - 1].empty())
                        dfs(l,i - 1);
                    if(dp[i + 1][r].empty())
                        dfs(i + 1,r);
                    for(int lval : dp[l][i - 1])
                        for(int rval : dp[i + 1][r])
                            dp[l][r].push_back(calculator(s[i],lval,rval));
                }
            }
            if(dp[l][r].empty())
                dp[l][r].push_back(stoi(s.substr(l,r - l + 1)));
            return;
        };
        
        dfs(0,SIZE - 1);
        
        return dp[0][SIZE - 1];
    }
};
// https://tinyurl.com/nbjf5cvj