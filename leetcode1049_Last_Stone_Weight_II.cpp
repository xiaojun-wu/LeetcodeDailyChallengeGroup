class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(),stones.end(),0);
        const int HALF = totalSum / 2;
        vector<int> dp(HALF + 1,0);
        dp[0] = 1;
        
        for(int n : stones){
            for(int t = HALF - n;t >= 0;t--)
                if(dp[t])
                    dp[t + n] = 1;
            if(dp[HALF])
                return totalSum - 2 * HALF;
        }
        
        for(int t = HALF;t >= 0;t--)
            if(dp[t])
                return totalSum - 2 * t;
        
        return -1;
    }
};

// https://tinyurl.com/tkmmmvvc