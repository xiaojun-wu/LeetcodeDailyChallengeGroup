class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int SIZE = obstacles.size(), MAXVAL = SIZE * 2;
        vector<int> dp(3,1), next(3,0);
        dp[1] = 0;
        
        for(int i = 1;i < SIZE;i++){
            next[0] = dp[0];
            next[1] = dp[1];
            next[2] = dp[2];
            if(obstacles[i] != 0)
                next[obstacles[i] - 1] = MAXVAL;
            int minVal = min({next[0],next[1],next[2]});
            for(int j = 0;j < 3;j++)
                if(j != obstacles[i] - 1)
                    next[j] = min(next[j],minVal + 1);
            swap(dp,next);
        }
        
        return min({dp[0],dp[1],dp[2]});
    }
};

// https://tinyurl.com/3e89yyrk