class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        const int SIZE = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        double average = totalsum / (SIZE * 1.0);
        
        for(int left = 1;left <= SIZE / 2;left++){
            int right = SIZE - left;
            if(abs(left * average - (int)(left * average)) > 1e-5 || abs(right * average - (int)(right * average)) > 1e-5)
                continue;
            int sum = left * average;
            vector<int> dp(sum + 1,0);
            unordered_map<int,unordered_set<int>> counts;
            dp[0] = 1;
            counts[0].insert(0);
            
            for(int n : nums){
                for(int i = sum - n;i >= 0;i--){
                    if(dp[i]){
                        dp[i + n] = 1;
                        for(int count : counts[i])
                            counts[i + n].insert(count + 1);
                    }
                    if(counts[sum].count(left))
                        return true;
                }
            }
        }
        
        return false;
    }
};
/*
a + b = size
a * avergae + b * average == totalsum.
(a + b) * average == totalsum
average = totalsum / (a + b)
average * a && average * b are a integer.
if there is possible to collect a elements from the given array and sum is a * average.
*/