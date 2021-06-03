class Solution {
public:
    /*
    I don't have leetcode Premium, so try to solve it in Lintcode.
    */
    int maximizeSweetness(vector<int> &sweetness, int K) {
        // write your code here
        const int SIZE = sweetness.size();
        int left = 1, right = 1e9, res = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 0, sweet = 0;
            bool isValid = false;
            for(int s : sweetness){
                if(sweet + s >= mid){
                    count++;
                    if(sweet + s == mid){
                        isValid = true;
                    }
                    sweet = 0;
                }
                else{
                    sweet+= s;
                }
            }
            if(count >= K + 1){
                if(isValid){
                    res = max(res,mid);
                }
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return res;
    }
};
// https://tinyurl.com/rr493uuf