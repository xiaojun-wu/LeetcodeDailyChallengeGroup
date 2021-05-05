class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int SIZE = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto& lhs,auto& rhs){
            if(lhs[0] != rhs[0])
                return lhs[0] < rhs[0];
            return lhs[1] > rhs[1];
        });
        int remove = 0, idx = 0;
        
        for(int i = 1;i < SIZE;i++){
            if(intervals[i][1] <= intervals[idx][1])
                remove++;
            else
                idx = i;
        }
        
        return SIZE - remove;
    }
};
// https://tinyurl.com/4tras96x