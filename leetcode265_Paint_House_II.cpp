class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0 || costs[0].size() == 0){
            return 0;
        }
        const int SIZE = costs.size(), K = costs[0].size();
        vector<vector<long>> dp(SIZE + 1,vector<long>(K + 1,INT_MAX));
        vector<vector<long>> minCost(SIZE + 1,vector<long>(2,INT_MAX));
        minCost[0][0] = minCost[0][1] = 0;

        for(int i = 0;i < K;i++){
            dp[0][i] = 0;
        }

        for(int i = 1;i <= SIZE;i++){
            long idx1 = 0, idx2 = 0;
            for(int k = 1;k <= K;k++){
                long cost = costs[i - 1][k - 1];
                if(k == minCost[i - 1][0]){
                    dp[i][k] = min(dp[i][k],cost + dp[i - 1][minCost[i - 1][1]]);
                }
                else{
                    dp[i][k] = min(dp[i][k],cost + dp[i - 1][minCost[i - 1][0]]);
                }
                if(dp[i][k] < dp[i][idx1]){
                    idx2 = idx1;
                    idx1 = k;
                }
                else if(dp[i][k] < dp[i][idx2]){
                    idx2 = k;
                }
            }
            minCost[i][0] = idx1;
            minCost[i][1] = idx2;
        }

        return dp[SIZE][minCost[SIZE][0]];
    }
};

// https://tinyurl.com/3r3xabp2