class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int SIZE = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0,pre = -1;i < SIZE;i++){
            if(nums[i] >= SIZE - i && SIZE - i > pre)
                return SIZE - i;
            pre = nums[i];
        }
        
        return -1;
    }
};