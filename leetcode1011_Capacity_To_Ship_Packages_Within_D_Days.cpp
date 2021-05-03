class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        const int SIZE = weights.size();
        int left = *max_element(weights.begin(),weights.end()), right = 500 * 5 * 10000;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int days = 0, load = 0;
            for(int i = 0;i < SIZE;i++){
                if(load + weights[i] > mid){
                    days++;
                    load = 0;
                }
                load+= weights[i];
            }
            if(days + 1 > D){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return left;
    }
};