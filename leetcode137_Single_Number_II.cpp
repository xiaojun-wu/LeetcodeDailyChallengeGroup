class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, sum = 0;
        for(int i = 0;i < 32;i++){
            sum = 0;
            for(int n : nums)
                sum+= (n >> i & 1);
            res+= ((sum % 3) << i);
        }
        
        return res;
    }
};
// https://tinyurl.com/4fkuvmjs