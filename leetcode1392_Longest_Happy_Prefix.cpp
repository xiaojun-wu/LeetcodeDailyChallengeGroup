typedef uint64_t ULL;
typedef pair<ULL,ULL> PULL;

class Solution {
public:
    string longestPrefix(string s) {
        const int LEN = s.length();
        const ULL BASE = 27;
        ULL left = 0, right = 0, mul = 1;
        int largestIdx = -1;
        
        for(int i = 0;i < LEN - 1;i++){
            left = left * BASE + (ULL)(s[i] - 'a');
            right = right + mul * (ULL)(s[LEN - i - 1] - 'a');
            mul*= BASE;
            if(left == right)
                largestIdx = i;
        }
        
        return s.substr(0,largestIdx + 1);
    }
};