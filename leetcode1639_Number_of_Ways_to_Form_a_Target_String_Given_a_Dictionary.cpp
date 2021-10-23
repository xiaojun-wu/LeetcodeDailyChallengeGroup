class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int SIZE = words[0].size(), LEN = target.length(), MOD = 1e9 + 7;
        if(SIZE < LEN)
            return 0;
        long long dp[1001][1001] = {0};
        int mp[1001][26] = {0};
        dp[0][0] = 1;
        long long res = 0;
        
        for(int i = 0;i <= SIZE;i++)
            dp[i][0] = 1;
        
        for(string word : words)
            for(int i = 0;i < word.length();i++)
                mp[i][word[i] - 'a']++;
        
        for(int i = 0;i < LEN;i++){
            long long presum = 0;
            for(int j = 0;j < SIZE;j++){
                long long count = mp[j][target[i] - 'a'];
                dp[j + 1][i + 1] = ((dp[j][i] * count) % MOD + presum) % MOD;
                presum = dp[j + 1][i + 1];
            }
        }
        
        return dp[SIZE][LEN];
    }
};