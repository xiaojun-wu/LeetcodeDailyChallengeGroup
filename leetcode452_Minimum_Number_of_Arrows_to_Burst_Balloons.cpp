class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int SIZE = points.size();
        if(SIZE == 0)
            return 0;
        sort(points.begin(),points.end(),[](auto& lhs,auto& rhs){
            return lhs[0] < rhs[0];
        });
        
        int res = 1;
        int left = points[0][0], right = points[0][1];
        
        for(int i = 1;i < SIZE;i++){
            if(points[i][0] <= right){
                left = points[i][0];
                right = min(right,points[i][1]);
            }
            else{
                res++;
                left = points[i][0];
                right = points[i][1];
            }
        }
        
        return res;
    }
};
