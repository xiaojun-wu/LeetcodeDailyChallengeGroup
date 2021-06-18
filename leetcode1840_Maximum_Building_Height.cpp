class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        /*
        check restrictions building's maxHeight + binary search.
        M = restrictions.size(), N = n
        TC: (M * log(N)), SC: (M)
        */
        const int SIZE = restrictions.size() + 1;
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end(),[](auto &lhs,auto &rhs){
            return lhs[0] < rhs[0];
        });
        vector<int> maxHeights(SIZE,0);
        int res = 0,preIdx = 1;
        
        for(int i = 1;i < SIZE;i++){
            int curIdx = restrictions[i][0], curHeight = restrictions[i][1];
            int len = curIdx - preIdx;
            int preHeight = maxHeights[i - 1];
            if(preHeight + len <= curHeight){
                maxHeights[i] = preHeight + len;
            }
            else{
                maxHeights[i] = curHeight;
            }
            preIdx = curIdx;
        }
        
        res = n - preIdx + maxHeights.back();
        
        for(int i = SIZE - 2;i >= 0;i--){
            int curIdx = restrictions[i][0], curHeight = maxHeights[i];
            int len = preIdx - curIdx;
            int preHeight = maxHeights[i + 1];
            if(preHeight + len <= curHeight){
                maxHeights[i] = preHeight + len;
                res = max(res,preHeight + len);
            }
            else{
                int low = max(preHeight,curHeight), high = 1e9;
                while(low <= high){
                    int mid = low + (high - low) / 2;
                    if(mid * 2 - curHeight - preHeight <= len)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                res = max(res,high);
            }
            preIdx = curIdx;
        }
        
        return res;
    }
};
// https://tinyurl.com/ef32eapp