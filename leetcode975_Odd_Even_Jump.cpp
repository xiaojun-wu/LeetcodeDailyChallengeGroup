class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        // dp + heap.O(NlogN)
        const int SIZE = arr.size();
        vector<bool> odd(SIZE,false), even(SIZE,false);
        odd[SIZE - 1] = true;
        even[SIZE - 1] = true;
        map<int,int> heap;
        heap[arr[SIZE - 1]] = SIZE - 1;
        int res = 1;
        
        for(int i = SIZE - 2;i >= 0;i--){
            auto it = heap.lower_bound(arr[i]);
            auto it2 = heap.upper_bound(arr[i]);
            if(it2 != heap.begin())
                it2--;
            if(it != heap.end())
                odd[i] = even[it->second];
            if(it2 != heap.end() && it2->first <= arr[i])
                even[i] = odd[it2->second];
            res+= odd[i];
            heap[arr[i]] = i;
        }
        
        return res;
    }
};
// https://github.com/xiaojun-wu/LeetcodeDailyChallengeGroup/blob/master/leetcode975_Odd_Even_Jump.cpp