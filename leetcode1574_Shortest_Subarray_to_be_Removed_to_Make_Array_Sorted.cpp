class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // sliding window
        const int SIZE = arr.size();
        if(SIZE == 1)
            return 0;
        int left = SIZE, right = SIZE - 1,res = SIZE;
        
        for(int i = 1;i < SIZE;i++)
            if(arr[i] < arr[i - 1]){
                left = i;
                break;
            }
        
        if(left == SIZE)
            return 0;
        
        for(int i = SIZE - 2;i >= 0;i--)
            if(arr[i] > arr[i + 1]){
                right = i;
                break;
            }
        
        res = min(SIZE - left,right + 1);
        int l = left - 1, r = SIZE - 1;
        while(l >= 0 && r > right){
            while(r > right && arr[r] >= arr[l]) r--;
            res = min(res,r - l);
            l--;
        }
        
        return res;
    }
};