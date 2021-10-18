class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1,n);
        vector<int> squares;
        dp[0] = 0;
        
        for(int i = 1;i * i <= n;i++)
            squares.push_back(i);
        
        for(int i = 1;i <= n;i++){
            if((int)(sqrt(i)) * (int)(sqrt(i)) == i)
                dp[i] = 1;
            else{
                for(int s : squares){
                    if(s * s > i)
                        break;
                    dp[i] = min(dp[i],dp[i - s * s] + 1);
                }
            }
        }
        
        return dp[n];
    }
};

// https://tinyurl.com/y5ac4ms5