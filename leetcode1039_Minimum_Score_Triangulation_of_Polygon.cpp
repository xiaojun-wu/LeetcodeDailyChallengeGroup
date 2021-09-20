class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        const int SIZE = values.size();
        vector<vector<int>> dp(SIZE,vector<int>(SIZE,INT_MAX));
        
        function<int(int,int)> dfs = [&](int left,int right) ->int {
            if(right - left < 2)
                return 0;
            if(dp[left][right] != INT_MAX)
                return dp[left][right];
            
            int minProduct = INT_MAX;
            
            for(int i = left + 1;i < right;i++)
                minProduct = min(minProduct,values[left] * values[right] * values[i] + dfs(left,i) + dfs(i,right));
            dp[left][right] = minProduct;
            
            return minProduct;
        };
        
        return dfs(0,SIZE -1);
    }
};

// https://tinyurl.com/4ynyfwzs