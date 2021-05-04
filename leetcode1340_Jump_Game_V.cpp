class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        // dp, N * d * 2
        const int SIZE = arr.size();
        vector<int> dp(SIZE,1);
        vector<pair<int,int>> nums;
        for(int i = 0;i < SIZE;i++)
            nums.emplace_back(arr[i],i);
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i < SIZE;i++){
            int idx = nums[i].second;
            for(int j = idx - 1;j >= idx - d && j >= 0 && arr[j] < arr[idx];j--)
                dp[idx] = max(dp[idx],dp[j] + 1);
            for(int j = idx + 1;j <= idx + d && j < SIZE && arr[j] < arr[idx];j++)
                dp[idx] = max(dp[idx],dp[j] + 1);
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
// https://tinyurl.com/rrks4dry