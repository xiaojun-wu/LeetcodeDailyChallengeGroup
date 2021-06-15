class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        /*
        two monotonic stack, two pass.
        TC: O(N), SC: O(N)
        */
        const int SIZE = nums.size(), MOD = 1e9 + 7;
        vector<long long> presum(1,0);
        vector<int> leftBound(SIZE,0), rightBound(SIZE,SIZE);
        vector<int> stack;
        long long maxMin = 0;
        
        for(long long n : nums)
            presum.push_back(presum.back() + n);
        
        for(int i = 0;i < SIZE;i++){
            while(!stack.empty() && nums[stack.back()] >= nums[i])
                stack.pop_back();
            if(!stack.empty())
                leftBound[i] = stack.back() + 1;
            stack.push_back(i);
        }
        stack.clear();
        for(int i = SIZE - 1;i >= 0;i--){
            while(!stack.empty() && nums[stack.back()] >= nums[i])
                stack.pop_back();
            if(!stack.empty())
                rightBound[i] = stack.back();
            stack.push_back(i);
        }
        
        for(int i = 0;i < SIZE;i++){
            int l = leftBound[i], r = rightBound[i];
            long long sum = presum[r] - presum[l];
            maxMin = max(maxMin,sum * (long long)(nums[i]));
        }
        
        return maxMin % MOD;
    }
};
// https://tinyurl.com/abvb2y2f