class Solution {
public:
    bool judgeSquareSum(int c) {
        /*
        two pointers + binary search
        TC : O(sqrt(c) * log(sqrt(c)))
        SC : O(1);
        */
//         const int LIMIT = sqrt(c);
//         for(int i = 0;i <= LIMIT;i++){
//             int target = c - i * i;
//             int left = 0, right = LIMIT;
//             while(left <= right){
//                 int mid = left + (right - left) / 2, val = mid * mid;
//                 if(val == target)
//                     return true;
//                 else if(val < target)
//                     left = mid + 1;
//                 else
//                     right = mid - 1;
//             }
//         }
        
//         return false;
        
        /*
        math
        TC : O(sqrt(c))
        SC : O(1);
        */
        const int LIMIT = sqrt(c);
        for(int i = 0;i <= LIMIT;i++){
            double n = sqrt(c - i * i);
            if((int)n == n) return true;
        }
        return false;
    }
};
// https://tinyurl.com/367cp3uc