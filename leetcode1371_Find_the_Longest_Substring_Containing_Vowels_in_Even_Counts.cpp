class Solution {
public:
    int findTheLongestSubstring(string s) {
        /*
        bitmask + dp
        TC: O(N), SC: O(32)
        */
        const int LEN = s.length();
        vector<char> vowels = {'a','e','i','o','u'};
        vector<int> leftMost(1 << 5,-2);
        int counts[26] = {0};
        leftMost[0] = -1;
        int res = 0;
        
        for(int i = 0;i < LEN;i++){
            counts[s[i] - 'a']++;
            int state = 0;
            for(int j = 0;j < vowels.size();j++)
                if(counts[vowels[j] - 'a'] % 2 != 0)
                    state+= (1 << j);
            if(leftMost[state] != -2)
                res = max(res,i - leftMost[state]);
            else
                leftMost[state] = i;
        }
        
        return res;
    }
};
// https://tinyurl.com/zc5cxs77