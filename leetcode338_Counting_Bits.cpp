class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1,0);
        
        for(int i = 0;i <= n / 2;i++){
            if((i << 1) <= n)
                res[i << 1] = res[i];
            if((i << 1) + 1 <= n)
                res[(i << 1) + 1] = res[i] + 1;
        }
        
        return res;
    }
};

// https://tinyurl.com/4bv8x3py