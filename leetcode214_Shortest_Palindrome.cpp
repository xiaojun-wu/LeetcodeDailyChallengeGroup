typedef uint64_t ULL;
typedef pair<ULL,ULL> PULL;

class Solution {
public:
    string shortestPalindrome(string s) {
        const ULL BASE1 = 1e9 + 3, BASE2 = 1e9 + 19, BASE = 1e9 + 3;
        ULL hash1 = 0, hash2 = 0, HEAD = 1;
        const int LEN = s.length();
        int largestIdx = -1;
        
        for(int i = 0;i < LEN;i++){
            hash1 = hash1 * BASE + (ULL)(s[i] - 'a');
            hash2 = hash2 + (ULL)(s[i] - 'a') * HEAD;
            HEAD*= BASE;
            if(hash1 == hash2)
                largestIdx = i;
        }
        
        string heading = largestIdx != LEN - 1?s.substr(largestIdx + 1):"";
        reverse(heading.begin(),heading.end());
        
        return heading + s;
    }
};
/*
This problem is looking for a longest palindrome from beginning of s.
if s[0:i] is a palindrome, we can add s[i + 1:] to the begin of s to make it a new palindrome

How to find the largest prefix polindrome?
We can using hash string method to find it.


*/

// https://tinyurl.com/2nev88t4