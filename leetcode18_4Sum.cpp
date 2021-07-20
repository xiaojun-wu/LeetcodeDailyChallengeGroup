class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int SIZE = nums.size();
        sort(nums.begin(),nums.end());
        long sum = 0;
        vector<vector<int>> res;
        vector<int> cur;
        
        function<void(int)> dfs = [&](int idx) {
            if(idx == SIZE)// pruning
                return;
            
            /*
            when only two element left, we do the two pointer search.
            */
            if(cur.size() == 2){
                if(sum > target / 2) return; // pruning.
                int left = idx, right = SIZE - 1;
                while(left < right){
                    long cursum = (long)nums[left] + (long)(nums[right]);
                    if(cursum + sum == target){
                        cur.push_back(nums[left]),cur.push_back(nums[right]);
                        res.push_back(cur);
                        cur.pop_back(), cur.pop_back();
                        left++, right--;
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(cursum + sum < target) left++;
                    else right--;
                }
                return;
            }
            
            // pick first and second element of 4sum.
            for(int i = idx, pre = -1e9 - 1;i < SIZE;i++){
                if(sum + (long)(nums[i]) > target && nums[i] >= 0) // pruning.
                    break;
                if(pre == nums[i])
                    continue;
                sum+= nums[i];
                cur.push_back(nums[i]);
                dfs(i + 1);
                sum-= nums[i];
                cur.pop_back();
                pre = nums[i];
            }
        };
        
        dfs(0);
        
        return res;
    }
};

// https://tinyurl.com/3hd7yzaw