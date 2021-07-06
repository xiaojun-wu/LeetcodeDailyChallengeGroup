class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        prefix and suffix product, two pass.
        TC : O(N)
        SC : O(1) (result array not count.)
        */
        const int SIZE = nums.size();
        vector<int> prefix(1,1);
        
        for(int i = 0;i < SIZE - 1;i++)
            prefix.push_back(prefix.back() * nums[i]);
        
        for(int i = SIZE - 1,suffix = 1;i >= 0;i--){
            prefix[i]*= suffix;
            suffix*= nums[i];
        }
        
        return prefix;
    }
};
