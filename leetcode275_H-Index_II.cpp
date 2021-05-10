class Solution {
public:
    int hIndex(vector<int>& citations) {
        // binary search
        const int SIZE = citations.size();
        int left = 0, right = SIZE - 1, res = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(citations[mid] <= SIZE - mid){
                left = mid + 1;
                res = max(res,citations[mid]);
            }
            else{
                right = mid - 1;
                res = max(res,SIZE - mid);
            }
        }
        return res;
    }
};
// https://tinyurl.com/rnwxbuyx