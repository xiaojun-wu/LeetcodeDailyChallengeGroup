class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /*
        prefix sum + math.
        TC: O(N), SC: O(N)
        */
        const int SIZE = nums.size();
        unordered_map<int,int> mp;
        long long sum = accumulate(nums.begin(),nums.end(),0ll), presum = 0;
        int target = sum % (long long)(p);
        int res = SIZE;
        mp[0] = -1;
        
        for(int i = 0;i < SIZE;i++){
            presum+= (long long)(nums[i]);
            mp[presum % p] = i;
            int m = (presum % p + p - target) % p;
            if(mp.count(m))
                res = min(res,i - mp[m]);
        }
        
        return res == SIZE?-1:res;
    }
};