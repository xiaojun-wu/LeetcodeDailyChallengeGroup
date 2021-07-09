class Solution {
public:
    int longestDecomposition(string text) {
        const int LEN = text.length();
        int mid = LEN / 2;
        int left = 0,right = 0, res = 0;
        
        function<int(int)> getPos = [&](int n) ->int {
            return LEN - n - 1;
        };
        
        while(right < mid){
            string head = text.substr(left,right - left + 1);
            string tail = text.substr(getPos(right),getPos(left) - getPos(right) + 1);
            if(head == tail){
                res+=2;
                left = right + 1;
            }
            right++;
        }
        
        if(LEN % 2 == 1 || right != left)
            res++;
        
        return res;
    }
};
/*
splite the given string into k parts and these parts are non-empty.
pi = p(k - i + 1);

if length of given string is LEN,
s[:i] == s[LEN - i - 1:]
we can check if s[i + 1 : LEN - i] can split into such format and what is largest part can split inot.

dp[i][j] means the maximum k of s[i:j] can split into.


xxx?? == ??xxx
x1x2x3?1?2 == ?3?4x4x5x6

?1?2 == x5x6
x1x2 == ?3?4

x1x2x3x5x6 == x1x2x4x5x6

x3 == x4

x1x2x3x5x6 == x1x2x3x5x6
*/