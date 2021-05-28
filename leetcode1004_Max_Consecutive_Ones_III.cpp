class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const int SIZE = A.size();
        deque<int> q;
        int res = 0;
        
        for(int l = 0,r = 0;r < SIZE;r++){
            if(A[r] == 0)
                q.push_back(r);
            if(q.size() <= K)
                res = max(res,r - l + 1);
            else{
                l = q.front() + 1;
                q.pop_front();
            }
        }
        
        return res;
    }
};
// https://tinyurl.com/sta8j8pj