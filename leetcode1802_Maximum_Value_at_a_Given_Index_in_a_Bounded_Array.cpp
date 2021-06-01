class Solution {
public:
    int maxValue(int n, int index, long long maxSum) {
        function<long long(long long,long long)> getSum = [&](long long l,long long r) ->long long {
            if(l < 0)
                return ((r + 1) * r / 2);
            return ((r + 1) * r / 2) - (l * (l - 1) / 2);
        };
        long long left = 1,right = maxSum;
        
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long leftLen = index, rightLen = n - index - 1;
            long long sum = getSum(mid - leftLen,mid) + getSum(mid - rightLen,mid) - mid;
            if(leftLen > mid - 1)
                sum+= leftLen - mid + 1;
            if(rightLen > mid - 1)
                sum+= rightLen - mid + 1;
            if(sum <= maxSum)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }
};