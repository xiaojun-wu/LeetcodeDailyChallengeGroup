class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        /*
        if current element is positive,
        longestPositive++ if longestPositive > 0
        longestNegative++ if longestNegative > 0
        if current element is negative
        longestPositive = longestNegative + 1 if longestNegative > 0
        longestNegative = longestPositive + 1 if longestPositive > 0
        if current element is zero
        longestPostive = longestNegative = 0
        */
        const int SIZE = nums.size();
        int res = 0, pos = 0,neg = 0;
        
        for(int i = 0;i < SIZE;i++){
            if(nums[i] > 0){
                pos++;
                neg = neg > 0?neg + 1:0;
            }
            else if(nums[i] < 0){
                swap(pos,neg);
                neg++;
                pos = pos > 0?pos + 1:0;
            }
            else{
                pos = neg = 0;
            }
            res = max(res,pos);
        }
        
        return res;
    }
};