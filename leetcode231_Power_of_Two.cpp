class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        
        while(n > 0){
            count+= (n & 1);
            n >>= 1;
        }
        
        return count == 1;
    }
};

// https://tinyurl.com/sx8d7w59