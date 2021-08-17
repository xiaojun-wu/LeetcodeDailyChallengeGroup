class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int SIZE = nums.size();
        nums.push_back(0);
        
        for(int i = 0;i < SIZE;i++){
            int val = nums[i] % 100000;
            nums[val]+= 100000;
        }
        
        for(int i = 0;i < SIZE;i++)
            if(nums[i] / 100000 != 1)
                return i;
        
        return SIZE;
    }
};