class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int SIZE = nums.size();
        priority_queue<int> pq;
        int minVal = INT_MAX;
        int res = INT_MAX;
        
        for(int n : nums){
            if(n % 2 == 1)
                n*= 2;
            minVal = min(minVal,n);
            pq.push(n);
        }
        
        while(pq.top() % 2 == 0){
            int n = pq.top();
            res = min(res,n - minVal);
            pq.pop();
            if(n % 2 == 0)
                n/= 2;
            minVal = min(minVal,n);
            pq.push(n);
        }
        
        return min(res,pq.top() - minVal);
    }
};
// https://tinyurl.com/68eu9c4s