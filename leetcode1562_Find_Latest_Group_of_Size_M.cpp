class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int SIZE = arr.size();
        int res = -1, count = 0;
        vector<pair<int,int>> intervals(SIZE + 1,pair<int,int>(0,0));
        
        for(int i = 0;i < SIZE;i++){
            int idx = arr[i];
            intervals[idx].first = idx;
            intervals[idx].second = idx;
            int left = idx, right = idx;
            if(idx > 1 && intervals[idx - 1].first != 0){
                left = intervals[idx - 1].first;
                if(intervals[idx - 1].second - intervals[idx - 1].first + 1 == m)
                    count--;
            }
            if(idx < SIZE && intervals[idx + 1].second != 0){
                right = intervals[idx + 1].second;
                if(intervals[idx + 1].second - intervals[idx + 1].first + 1 == m)
                    count--;
            }
            intervals[left].second = right;
            intervals[right].first = left;
            if(right - left + 1 == m)
                count++;
            if(count > 0)
                res = i + 1;
        }
        
        return res;
    }
};