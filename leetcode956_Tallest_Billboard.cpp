class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        const int SIZE = rods.size(), TOTALSTATES = 1 << SIZE;
        int totalSum = accumulate(rods.begin(),rods.end(),0);
        vector<int> dp(10001,-1);
        dp[5000] = 0;
        
        for(int n : rods){
            vector<int> next = dp;
            for(int i = 10000;i >= 0;i--){
                if(dp[i] != -1){
                    if(i - n >= 0)
                        next[i - n] = max(next[i - n],dp[i]);
                    if(i + n <= totalSum + 5000)
                        next[i + n] = max(next[i + n],dp[i] + n);
                }
            }
            swap(dp,next);
        }
        
        return dp[5000];
    }
};

// https://tinyurl.com/ym2epnr4