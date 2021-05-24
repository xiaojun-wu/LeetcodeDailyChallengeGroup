class Solution {
public:
    int countTriplets(vector<int>& arr) {
        /*
        find the number of subarray xor is cur;
        TC: O(N), SC: O(N)
        */
        const int SIZE = arr.size();
        unordered_map<int,int> totalLens;
        unordered_map<int,int> count;
        totalLens[0] = -1;
        count[0] = 1;
        int res = 0;
        
        for(int i = 0,x = 0;i < SIZE;i++){
            x^= arr[i];
            if(totalLens.count(x))
                res+= ((i - 1) * count[x] - totalLens[x]);
            totalLens[x]+= i;
            count[x]++;
        }
        
        return res;
    }
};
// https://tinyurl.com/3r9sbcph