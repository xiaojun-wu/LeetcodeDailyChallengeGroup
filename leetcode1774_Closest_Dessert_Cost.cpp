class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        const int BSIZE = baseCosts.size();
        const int TSIZE = toppingCosts.size();
        vector<int> dp(target + 2,0);
        dp[0] = 1;
        dp[target + 1] = 10000 * 10000 * 2;
        int res = INT_MAX;
        
        sort(baseCosts.begin(),baseCosts.end());
        
        for(int i = 0;i < TSIZE;i++){
            for(int k = 0;k < 2;k++){
                for(int j = target;j >= 0;j--){
                    if(dp[j]){
                        if(j + toppingCosts[i] <= target)
                            dp[j + toppingCosts[i]] = 1;
                        else
                            dp[target + 1] = min(dp[target + 1],j + toppingCosts[i]);
                    }
                }
            }
        }
        
        for(int i = 0;i <= target;i++)
            if(dp[i]){
                auto it = upper_bound(baseCosts.begin(),baseCosts.end(),target - i);
                if(it != baseCosts.end())
                    if(abs(res - target) > abs(*it + i - target))
                        res = *it + i;
                if(it != baseCosts.begin()){
                    it--;
                    if(abs(res - target) >= abs(*it + i - target))
                        res = *it + i;
                }
            }
        
        for(int b : baseCosts)
            if(abs(res - target) > abs(b + dp[target + 1] - target))
                res = b + dp[target + 1];
        
        return res;
    }
};