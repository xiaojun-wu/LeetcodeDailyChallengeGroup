class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        const int SIZE = dist.size();
        vector<double> travalTimes(SIZE,0);
        vector<double> dp(SIZE,100000001);
        dp[0] = 0;
        
        for(int i = 0;i < SIZE;i++)
            travalTimes[i] = dist[i] / (double)(speed);
        
        for(int i = 0;i < SIZE - 1;i++){
            double time = travalTimes[i];
            for(int j = i + 1;j > 0;j--)
                dp[j] = min(ceil(dp[j] + time - 1e-9),dp[j - 1] + time);
            dp[0]+= ceil(time);
        }
        
        for(int i = 0;i < SIZE;i++)
            if(dp[i] + travalTimes.back() <= (double)(hoursBefore))
                return i;
        
        return -1;
    }
};

// https://tinyurl.com/242ebfhd