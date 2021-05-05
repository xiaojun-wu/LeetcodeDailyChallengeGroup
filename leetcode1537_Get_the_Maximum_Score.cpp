class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int SIZE1 = nums1.size(), SIZE2 = nums2.size(), MOD = 1e9 + 7;
        int idx1 = 0, idx2 = 0;
        long long sum1 = 0, sum2 = 0;
        
        while(idx1 < SIZE1 && idx2 < SIZE2){
            if(nums1[idx1] < nums2[idx2])
                sum1+= nums1[idx1++];
            else if(nums1[idx1] > nums2[idx2])
                sum2+= nums2[idx2++];
            else{
                sum1 = max(sum1,sum2) + nums1[idx1];
                sum2 = sum1;
                idx1++;
                idx2++;
            }
        }
        while(idx1 < SIZE1)
            sum1+= nums1[idx1++];
        while(idx2 < SIZE2)
            sum2+= nums2[idx2++];
        
        return max(sum1,sum2) % MOD;
    }
};