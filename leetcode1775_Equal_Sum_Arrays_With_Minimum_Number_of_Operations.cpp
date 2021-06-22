class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        /*
        two pointers + greedy.
        */
        int sum1 = accumulate(nums1.begin(),nums1.end(),0);
        int sum2 = accumulate(nums2.begin(),nums2.end(),0);
        int res = 0;
        if(sum1 == sum2)
            return res;
        
        // let nums1's sum > nums2's sum.
        if(sum1 < sum2){
            swap(nums1,nums2);
            swap(sum1,sum2);
        }
        const int SIZE1 = nums1.size(), SIZE2 = nums2.size();
        if(SIZE1 > SIZE2 * 6)
            return -1;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int r1 = SIZE1 - 1,l2 = 0;
        
        while(sum1 > sum2){
            int diff1 = nums1[r1] - 1, diff2 = 6 - nums2[l2];
            if(diff1 > diff2){
                nums1[r1] = 1;
                if(r1 > 0) r1--;
                sum1-= diff1;
            }
            else{
                nums2[l2] = 6;
                if(l2 < SIZE2 - 1) l2++;
                sum2+= diff2;
            }
            res++;
        }
        
        return res;
    }
};