class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // stack. O(N)
        const int SIZE = nums.size();
        deque<int> q;
        q.emplace_back(0);
        
        for(int i = 1;i < SIZE;i++){
            int curSum = nums[i] + nums[q.front()];
            while(!q.empty() && nums[q.back()] <= curSum) q.pop_back();
            q.push_back(i);
            nums[i] = curSum;
            if(i - q.front() >= k)
                q.pop_front();
        }
        
        return nums[q.back()];
    }
};