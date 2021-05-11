class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        /*
        choose the larger difference first?
        */
        const int SIZE = tasks.size();
        sort(tasks.begin(),tasks.end(),[](auto& lhs,auto& rhs){
            if(lhs[1] - lhs[0] != rhs[1] - rhs[0])
                return lhs[1] - lhs[0] > rhs[1] - rhs[0];
            return lhs[1] > rhs[1];
        });
        int res = 0, cur = 0;
        
        for(int i = 0;i < SIZE;i++){
            if(cur < tasks[i][1]){
                res+= tasks[i][1] - cur;
                cur = tasks[i][1];
            }
            cur-= tasks[i][0];
        }
        
        return res;
    }
};
// https://tinyurl.com/nmsfc58p