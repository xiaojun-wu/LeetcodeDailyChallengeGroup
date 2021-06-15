class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        /*
        Greedy + monotonic stack.
        TC:O(N), SC:O(N).
        DP is easy, Greedy is hard.
        */
        const int SIZE = arr.size();
        int res = 0;
        vector<int> stack(1,INT_MAX);
        
        for(int i = 0;i < SIZE;i++){
            while(stack.back() < arr[i]){
                int cur = stack.back();
                stack.pop_back();
                res+= cur * min(arr[i],stack.back());
            }
            stack.push_back(arr[i]);
        }
        while(stack.size() > 2){
            int cur = stack.back();
            stack.pop_back();
            res+= cur * stack.back();
        }
        
        return res;
    }
};