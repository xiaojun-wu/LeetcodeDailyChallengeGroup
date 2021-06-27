class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        /*
        prefix and suffix record.
        idea: if nums[i] <= nums[i - 1] or nums[i] >= nums[i + 1], it is a conflict.
        if nums[0:i - 1] is ascending and nums[i + 1:] is ascending
        also nums[i - 1] < nums[i + 1], we can make array strictly increasing by
        remove nums[i].
        Or if the array increasing already, it also a valid state.
        so we can make a prefixOrder array and prefixOrder[i] = 1 means the prefix from 0 to i is strictly increasing.
        also make the suffixOrder array.
        Than we iterator array, if nums[i] is conflict and remove it can make array increasing. we return ture.
        If we can't find the nums[i] that conflict, the array already increasing and return true.
        If there is nums[i] is conflict but we can't find any way to remove one element to make array increasing, return false.
        
        TC : O(N)
        SC : O(N)
        */
        nums.insert(nums.begin(),0);
        nums.push_back(1001);
        const int SIZE = nums.size();
        vector<int> prefixOrder(SIZE,0), suffixOrder(SIZE,0);
        prefixOrder[0] = 1, suffixOrder[SIZE - 1] = 1;
        bool isConflicted = false;
        
        for(int i = 1;i < SIZE && prefixOrder[i - 1];i++)
            if(nums[i] > nums[i - 1])
                prefixOrder[i] = 1;
        
        for(int i = SIZE - 2;i >= 0 && suffixOrder[i + 1];i--)
            if(nums[i] < nums[i + 1])
                suffixOrder[i] = 1;
        
        for(int i = 1;i < SIZE - 1;i++){
            if(nums[i] <= nums[i - 1] || nums[i] >= nums[i + 1]){
                isConflicted = true;
                if(prefixOrder[i - 1] && suffixOrder[i + 1] && nums[i - 1] < nums[i + 1])
                    return true;
            }
        }
        
        return isConflicted?false:true;
    }
};