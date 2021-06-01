class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int SIZE = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> presum(SIZE + 1,0);
        int left = 0, right = arr.back(), val = -1, res = -1;
        
        for(int i = 0;i < SIZE;i++)
            presum[i + 1]+= presum[i] + arr[i];
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            int idx = upper_bound(arr.begin(),arr.end(),mid) - arr.begin();
            int sum = presum[idx] + (SIZE - idx) * mid;
            int diff1 = abs(val - target), diff2 = abs(sum - target);
            if(diff1 > diff2 || (diff1 == diff2 && res > mid)){
                res = mid;
                val = sum;
            }
            if(sum < target)
                left = mid + 1;
            else if(sum > target)
                right = mid - 1;
            else
                break;
        }
        
        return res;
    }
};
// https://tinyurl.com/mnm6pk62