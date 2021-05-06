class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int SIZE = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),[](auto& lhs,auto& rhs){
            if(lhs[0] != rhs[0])
                return lhs[0] < rhs[0];
            return lhs[1] < rhs[1];
        });
        
        res.push_back(intervals[0]);
        
        for(int i = 1;i < SIZE;i++){
            if(res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        
        return res;
    }
};
// https://tinyurl.com/25xr5595