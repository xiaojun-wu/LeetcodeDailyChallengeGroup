class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        /*
        store the total distance instead of the speeding time.
        avoid to precision loss.
        */
        const int SIZE = dist.size();
        vector<long long> dp(SIZE,1000000000);
        double _speed = speed;
        dp[0] = 0;
        
        for(int i = 0;i < SIZE - 1;i++){
            for(int j = i + 1;j > 0;j--){
                long long a = (long long)(ceil((dp[j] + dist[i]) / _speed) * _speed);
                long long b = dp[j - 1] + dist[i];
                dp[j] = min(a,b);
            }
            dp[0]+= (long long)(ceil(dist[i] / _speed) * _speed);
        }
        
        for(int i = 0;i < SIZE;i++)
            if((dp[i] / _speed) + (dist.back() / _speed) <= (double)(hoursBefore))
                return i;
        
        return -1;
    }
};

// https://tinyurl.com/242ebfhd