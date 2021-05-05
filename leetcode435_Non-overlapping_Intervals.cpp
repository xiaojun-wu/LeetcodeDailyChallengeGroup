class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& lhs,auto& rhs){
            if(lhs[1] != rhs[1])
                return lhs[1] < rhs[1];
            return lhs[0] > rhs[0];
        });
        int res = 0, end = -20001;
        
        for(vector<int>& interval : intervals){
            if(interval[0] >= end)
                end = interval[1];
            else
                res++;
        }
        
        return res;
    }
};