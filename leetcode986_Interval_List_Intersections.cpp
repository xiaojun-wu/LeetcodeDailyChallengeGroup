class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // two pointers.
        const int SIZE1 = firstList.size(), SIZE2 = secondList.size();
        vector<vector<int>> res;
        int idx1 = 0, idx2 = 0;
        
        while(idx1 < SIZE1 && idx2 < SIZE2){
            int left = max(firstList[idx1][0],secondList[idx2][0]);
            int right = min(firstList[idx1][1],secondList[idx2][1]);
            if(left <= right)
                res.push_back({left,right});
            if(firstList[idx1][1] < secondList[idx2][1])
                idx1++;
            else
                idx2++;
        }
        
        return res;
    }
};
// https://tinyurl.com/mr7ws223