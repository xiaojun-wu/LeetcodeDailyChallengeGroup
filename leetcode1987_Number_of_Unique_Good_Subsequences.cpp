class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int LEN = binary.length(), MOD = 1e9 + 7;
        long one = 0, zero = 0, hasZero = 0;
        
        for(int i = LEN - 1;i >= 0;i--){
            long val = (one + zero + 1) % MOD;
            hasZero|= binary[i] == '0';
            if(binary[i] == '0')
                zero = val;
            else
                one = val;
        }
        
        return (one + hasZero) % MOD;
    }
};

// https://tinyurl.com/vhj35zjv