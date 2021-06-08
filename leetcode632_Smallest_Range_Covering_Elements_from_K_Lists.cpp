class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int SIZE = nums.size();
        multimap<int,pair<int,int>> heap;
        int len = INT_MAX;
        vector<int> res;
        
        for(int i = 0;i < SIZE;i++)
            heap.emplace(nums[i][0],make_pair(i,0));
        
        while(!heap.empty()){
            auto it = heap.begin();
            auto it2 = prev(heap.end());
            int left = it->first, right = it2->first, i = it->second.first, j = it->second.second;
            if(right - left < len){
                res = {left,right};
                len = right - left;
            }
            heap.erase(it);
            if(nums[i].size() == j + 1)
                break;
            heap.emplace(nums[i][j + 1],make_pair(i,j + 1));
        }
        
        return res;
    }
};
/*
the smallest range [l,r] that l and r are exist in nums.
if a = l, we want to find the smallest b that all lists have at least one
number in range [a,b].
*/

// https://tinyurl.com/eh8k6hdb