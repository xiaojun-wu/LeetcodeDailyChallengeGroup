class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        deque<int> q;
        int res = 0, l = 0,r = 0;
        
        for(;r < SIZE;r++){
            if(nums[r] % 2 == 0) continue;
            if(q.size() + 1 > k){
                res+= (q.front() - l + 1) * (r - q.back());
                l = q.front() + 1;
                q.pop_front();
            }
            q.push_back(r);
        }
        
        if(q.size() == k)
            res+= (q.front() - l + 1) * (r - q.back());
        
        return res;
    }
};
// https://tinyurl.com/t55w4j9j