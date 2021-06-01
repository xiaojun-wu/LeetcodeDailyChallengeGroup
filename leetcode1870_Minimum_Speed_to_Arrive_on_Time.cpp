class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int SIZE = dist.size();
        long left = 0, right = INT_MAX, res = INT_MAX;
        bool isMatch = false;
        
        while(left <= right){
            long mid = left + (right - left) / 2;
            double h = 0;
            for(int i = 0;i < SIZE - 1;i++)
                h+= ceil((double)(dist[i]) / (double)(mid));
            h+= (double)(dist.back()) / (double)(mid);
            if(h <= hour){
                isMatch = true;
                res = min(res,mid);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if(!isMatch)
            return -1;
        return res;
    }
};