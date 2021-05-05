class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        int left = k, right = k, minVal = nums[k], res = minVal;
        
        while(left > 0 || right < SIZE - 1){
            if(left > 0 && right < SIZE -1){
                nums[left - 1] > nums[right + 1]?left--:right++;
                minVal = min(minVal,min(nums[left],nums[right]));
            }
            else if(left > 0)
                minVal = min(minVal,nums[--left]);
            else
                minVal = min(minVal,nums[++right]);
            res = max(res,(right - left + 1) * minVal);
        }
        
        return res;
    }
};
// https://github.com/xiaojun-wu/LeetcodeDailyChallengeGroup/blob/master/leetcode1793_Maximum_Score_of_a_Good_Subarray.cpp