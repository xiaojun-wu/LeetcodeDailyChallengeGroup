class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int SIZE = intervals.size();
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1], idx = 0;
        
        while(idx < SIZE && intervals[idx][1] < left)
            res.push_back(intervals[idx++]);
        
        while(idx < SIZE && intervals[idx][0] <= right){
            left = min(left,intervals[idx][0]);
            right = max(right,intervals[idx++][1]);
        }
        
        res.push_back({left,right});
        
        while(idx < SIZE){
            res.push_back(intervals[idx++]);
        }
        
        return res;
    }
};
// https://tinyurl.com/2mx75fkw