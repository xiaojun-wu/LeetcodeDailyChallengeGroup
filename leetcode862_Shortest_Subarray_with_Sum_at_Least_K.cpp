class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int SIZE = A.size();
        int res = SIZE + 1;
        long long sum = 0;
        vector<long long> presum(1,0);
        deque<int> q;
        q.push_back(0);
        
        for(int i = 0;i < SIZE;i++){
            sum+= (long long)(A[i]);
            while(!q.empty() && sum - presum[q.back()] >= K){
                res = min(res,i - q.back() + 1);
                q.pop_back();
            }
            presum.push_back(sum);
            while(!q.empty() && presum[q.front()] >= presum[i + 1])
                q.pop_front();
            q.emplace_front(i + 1);
        }
        
        return res == SIZE + 1?-1:res;
    }
};
// https://tinyurl.com/tm2jyvus