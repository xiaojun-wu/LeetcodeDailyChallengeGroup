class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        /*
        two pointers.
        TC : O(M + N)
        SC : O(1)
        */
        const int SIZE1 = nums1.size(), SIZE2 = nums2.size(), MOD = 1e9 + 7;
        int res = 0;
        int idx1 = SIZE1 - 1,idx2 = SIZE2 - 1;
        long long pre1 = 0, pre2 = 0;
        
        while(idx1 >= 0 && idx2 >= 0){
            if(nums1[idx1] > nums2[idx2])
                pre1+= (long long)nums1[idx1--];
            else if(nums1[idx1] < nums2[idx2])
                pre2+= (long long)nums2[idx2--];
            else{
                pre1 = pre2 = max(pre1,pre2) + (long long)(nums1[idx1]);
                idx1--;
                idx2--;
            }
        }
        while(idx1 >= 0)
            pre1+= (long long)nums1[idx1--];
        while(idx2 >= 0)
            pre2+= (long long)nums2[idx2--];
        
        return max(pre1,pre2) % MOD;
    }
};
// https://tinyurl.com/7bf3d5ps