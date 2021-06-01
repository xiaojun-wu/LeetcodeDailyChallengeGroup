class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        const int SIZE = position.size();
        sort(position.begin(),position.end());
        int left = 1, right = position.back();
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 1, pre = position[0];
            for(int i = 1;i < SIZE && count < m;i++){
                if(position[i] - pre >= mid){
                    count++;
                    pre = position[i];
                }
            }
            if(count >= m)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }
};