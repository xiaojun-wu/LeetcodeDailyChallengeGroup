class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int SIZE = locations.size(), MOD = 1e9 + 7;
        int dp[201][101] = {0};
        dp[fuel][start] = 1;
        int res = 0;
        
        for(int f = fuel;f >= 1;f--){
            for(int i = 0;i < SIZE;i++){
                if(dp[f][i] == 0)
                    continue;
                for(int j = 0;j < SIZE;j++){
                    if(i == j)
                        continue;
                    int dis = abs(locations[i] - locations[j]);
                    if(f >= dis)
                        dp[f - dis][j] = (dp[f - dis][j] + dp[f][i]) % MOD;
                }
            }
        }
        
        for(int f = 0;f <= fuel;f++)
            res = (res + dp[f][finish]) % MOD;
        
        return res;
    }
};

// https://tinyurl.com/46e8rh4a