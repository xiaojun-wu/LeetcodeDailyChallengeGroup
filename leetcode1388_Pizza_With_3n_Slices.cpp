class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        const int SIZE = slices.size();
        
        function<int(int,int)> helper = [&](int start,int end) ->int {
            vector<vector<int>> dp(SIZE,vector<int>(SIZE / 3,0));
            while(start < end){
                dp[start][0] = slices[start];
                if(start - 1 >= 0)
                    dp[start][0] = max(dp[start][0],dp[start -1][0]);
                if(start - 2 < 0){
                    start++;
                    continue;
                }
                for(int i = 1;i < SIZE / 3;i++){
                    dp[start][i] = max(dp[start - 2][i - 1] + slices[start],dp[start - 1][i]);
                }
                start++;
            }
            return dp[end - 1][SIZE / 3 - 1];
        };
        
        return max(helper(0,SIZE - 1),helper(1,SIZE));
    }
};

// https://tinyurl.com/et8p57u