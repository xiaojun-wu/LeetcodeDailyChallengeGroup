class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        const int SIZE = nums.size();
        int res = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i = 0,sum = 0;i < SIZE;i++){
            sum+= nums[i];
            if(mp.count(sum - k))
                res = max(res,i - mp[sum - k]);
            if(!mp.count(sum))
                mp[sum] = i;
        }

        return res;
    }
};