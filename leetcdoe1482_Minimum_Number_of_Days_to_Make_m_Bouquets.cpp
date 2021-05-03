gotclass Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int SIZE = bloomDay.size();
        if(m * k > SIZE)
            return -1;
        int left = 1, right = 1e9;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 0, sum = 0;
            for(int b : bloomDay){
                if(b <= mid)
                    sum++;
                else
                    sum = 0;
                if(sum == k){
                    count++;
                    sum = 0;
                }
            }
            if(count >= m)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};