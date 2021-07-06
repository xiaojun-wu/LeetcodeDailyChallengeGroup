class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        unordered_map<int,int> mp;
        int res = 0;
        mp[0] = 1;
        
        for(int i = 0,sum = 0;i < SIZE;i++){
            sum+= nums[i];
            if(mp.count(sum - k))
                res+= mp[sum - k];
            mp[sum]++;
        }
        
        return res;
    }
};

// https://tinyurl.com/5hbsdb7k