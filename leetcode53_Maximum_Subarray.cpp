class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = 0, res = INT_MIN;
        
        for(int n : nums){
            cursum+= n;
            res = max(res,cursum);
            cursum = max(cursum,0);
        }
        
        return res;
    }
};

// https://tinyurl.com/3mazwau3