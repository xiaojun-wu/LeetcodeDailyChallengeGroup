class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        const int SIZE = cost.size();
        string res = "";
        vector<int> dp(target + 1,0);
        vector<int> indice(target + 1,-1);
        dp[0] = 1;
        
        for(int t = 0;t <= target;t++)
            for(int i = 8;i >= 0;i--)
                if(cost[i] <= t && dp[t - cost[i]] && dp[t - cost[i]] + 1 > dp[t]){
                    dp[t] = dp[t - cost[i]] + 1;
                    indice[t] = i + 1;
                }
        
        if(dp[target] == 0)
            return "0";
        
        while(target > 0){
            res+= indice[target] + '0';
            target-= cost[indice[target] - 1];
        }
        
        return res;
    }
};

// https://tinyurl.com/bz2khb8c