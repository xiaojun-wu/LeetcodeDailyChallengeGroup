class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        sort(nums.begin(),nums.end());
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum % k != 0 || nums.back() > totalSum / k)
            return false;
        int target = totalSum / k;
        vector<int> taken(SIZE,0);
        
        function<bool(int,int,int)> dfs = [&](int count,int sum,int start) ->bool {
            if(sum == target){
                if(count == SIZE)
                    return true;
                return dfs(count,0,0);
            }
            for(int i = start;i < SIZE;i++){
                if(taken[i]) continue;
                if(sum + nums[i] > target) break;
                taken[i] = 1;
                if(dfs(count + 1,sum + nums[i],i + 1))
                    return true;
                taken[i] = 0;
            }
            
            return false;
        };
        
        return dfs(0,0,0);
    }
};