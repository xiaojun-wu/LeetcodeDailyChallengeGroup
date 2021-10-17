class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0)
            return 1.0;
        if(k + maxPts - 1 <= n)
            return 1.0;
        const double BASE_PROBABILITY = 1 / (maxPts * 1.0);
        vector<double> dp(n + 1,0);
        double prePro = 0, res = 0;
        
        for(int i = 1;i <= min(maxPts,k - 1);i++){
            dp[i] = BASE_PROBABILITY * (prePro + 1);
            prePro+= dp[i];
        }
        
        for(int i = min(maxPts + 1,k);i <= n;i++){
            if(i > maxPts)
                prePro-= dp[i - maxPts - 1];
            else
                dp[i]+= BASE_PROBABILITY;
            dp[i]+= prePro * BASE_PROBABILITY;
            if(i < k)
                prePro+= dp[i];
        }
        
        for(int i = n;i >= k;i--)
            res+= dp[i];
        
        return res;
    }
};