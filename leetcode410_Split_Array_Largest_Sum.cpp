class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int SIZE = nums.size();
        long sum = 0;
        for(long n : nums)
            sum+= n;
        long left = *max_element(nums.begin(),nums.end()), right = sum;
        while(left <= right){
            long mid = left + (right - left) / 2, curSum = 0;
            int count = 1;
            for(long n : nums){
                if(curSum + n > mid){
                    count++;
                    curSum = 0;
                }
                curSum+= n;
            }
            if(count <= m)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};