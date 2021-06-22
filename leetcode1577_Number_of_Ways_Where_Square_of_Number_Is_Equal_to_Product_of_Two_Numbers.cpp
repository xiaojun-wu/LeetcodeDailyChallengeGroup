class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        /*
        brute force + hashmap with count frequences.
        TC : O(M * N), SC : O(M + N)
        */
        const int SIZE1 = nums1.size(), SIZE2 = nums2.size();
        int res = 0;
        unordered_map<int,int> freq1, freq2;
        
        for(int n : nums1)
            freq1[n]++;
        for(int n : nums2)
            freq2[n]++;
        
        function<void()> helper = [&](){
            for(auto& [num1,count1] : freq1){
                for(auto& [num2,count2] : freq2){
                    long long sqr = (long)num1 * (long)num1;
                    if(sqr % num2 != 0) continue;
                    if(sqr / num2 > INT_MAX || !freq2.count(sqr / num2)) continue;
                    int num3 = sqr / num2,count3 = freq2[num3];
                    if(num2 == num3)
                        res+= count1 * (count2 * (count2 - 1) / 2);
                    else if(num2 < num3){
                        res+= count1 * count2 * count3;
                    }
                }
            }
        };
        
        helper();
        swap(freq1,freq2);
        helper();
        
        return res;
    }
};
// https://tinyurl.com/9f59s32p