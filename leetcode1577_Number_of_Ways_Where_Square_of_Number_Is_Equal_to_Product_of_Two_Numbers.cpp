class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int SIZE1 = nums1.size(), SIZE2 = nums2.size();
        int res = 0;
        unordered_map<long,int> mp1, mp2;
        
        for(int i = 0;i < SIZE1;i++)
            for(int j = i + 1;j < SIZE1;j++)
                mp1[(long)nums1[i] * (long)nums1[j]]++;
        
        for(int i = 0;i < SIZE2;i++)
            for(int j = i + 1;j < SIZE2;j++)
               mp2[(long)(nums2[i]) * (long)(nums2[j])]++;
        
        for(long n : nums1)
            if(mp2.count(n * n))
                res+= mp2[n * n];
        for(long n : nums2)
            if(mp1.count(n * n))
                res+= mp1[n * n];
        
        return res;
    }
};