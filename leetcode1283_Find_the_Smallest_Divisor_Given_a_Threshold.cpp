class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        const int SIZE = nums.size();
        int left = 1, right = 1000000;
        while(left <= right){
            double mid = left + (right - left) / 2;
            long sum = 0;
            for(long n : nums)
                sum+= ceil(n / mid);
            if(sum <= threshold)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
// https://tinyurl.com/y393k3a3