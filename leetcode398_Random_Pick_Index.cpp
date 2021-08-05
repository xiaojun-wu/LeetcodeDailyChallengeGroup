class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
            arr.emplace_back(nums[i],i);
        sort(arr.begin(),arr.end());
    }
    
    int pick(int target) {
        int start = getIdx(target), end = getIdx(target + 1);
        return arr[rand() % (end - start) + start].second;
    }
    int getIdx(int target){
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid].first >= target)
                right--;
            else
                left++;
        }
        return left;
    }
private:
    vector<pair<int,int>> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */