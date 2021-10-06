class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1000001;
        vector<vector<vector<int>>> dp(target + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,INF)));
        vector<vector<vector<int>>> minCost(target + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,INF)));
        int res = INF;
        
        for(int i = 0;i <= n;i++){
            dp[0][0][i] = 0;
            minCost[0][0][i] = 0;
        }
        
        for(int t = 1;t <= target;t++){
            for(int i = t - 1;i < m;i++){
                if(houses[i] == 0){
                    for(int color = 1;color <= n;color++){
                        int curcost = cost[i][color - 1];
                        dp[t][i + 1][color] = min(dp[t][i][color],minCost[t - 1][i][color]) + curcost;
                    }
                }
                else{
                    int color = houses[i];
                    dp[t][i + 1][color] = min(dp[t][i][color],minCost[t - 1][i][color]);
                }
            }
            for(int i = 0;i < m;i++){
                vector<pair<int,int>> arr;
                for(int color = 1;color <= n;color++){
                    arr.emplace_back(dp[t][i + 1][color],color);
                }
                sort(arr.begin(),arr.end());
                for(int color = 1;color <= n;color++){
                    if(color == arr[0].second){
                        if(n > 1)
                            minCost[t][i + 1][color] = arr[1].first;
                        else
                            minCost[t][i + 1][color] = INF;
                    }
                    else{
                        minCost[t][i + 1][color] = arr[0].first;
                    }
                }
            }
        }
        
        for(int color = 1;color <= n;color++)
            res = min(res,dp[target][m][color]);
        
        return res==INF?-1:res;
    }
};