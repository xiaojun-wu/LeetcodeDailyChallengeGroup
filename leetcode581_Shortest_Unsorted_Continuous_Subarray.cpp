class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        the target array might in beginning of nums, end of nums or middle of nums.
        1. find the sorted part of beginning and sort part of end.
        2. find minimum and maximum element in middle.
        3. find fist element in first part that larget than minimum in middle,
        find first smaller element in end part than maximum in middle.
        */
        const int SIZE = nums.size();
        if(SIZE == 1)
            return 0;
        int firstEnd = 0, secondBegin = SIZE - 1, maxOne = INT_MIN, minOne = INT_MAX;;
        while(firstEnd < SIZE - 1 && nums[firstEnd] <= nums[firstEnd + 1]) firstEnd++;
        while(secondBegin > 0 && nums[secondBegin] >= nums[secondBegin - 1]) secondBegin--;
        // already sorted.
        if(firstEnd == SIZE - 1)
            return 0;
        for(int i = firstEnd;i <= secondBegin;i++){
            maxOne = max(maxOne,nums[i]);
            minOne = min(minOne,nums[i]);
        }
        auto it = upper_bound(nums.begin(),nums.begin() + firstEnd + 1,minOne);
        auto it2 = lower_bound(nums.begin() + secondBegin,nums.end(),maxOne);
        it2--;
        return it2 - it + 1;
    }
};