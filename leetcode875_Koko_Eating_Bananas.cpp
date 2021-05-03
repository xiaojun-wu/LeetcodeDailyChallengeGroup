class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        const int SIZE = piles.size();
        long long left = 1, right = 0;
        for(long long p : piles)
            right+= p;
        
        while(left <= right){
            double mid = left + (right - left) / 2;
            int count = 0;
            for(double n : piles)
                count+= ceil(n / mid);
            if(count <= H)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};