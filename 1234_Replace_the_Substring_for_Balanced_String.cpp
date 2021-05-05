class Solution {
public:
    int balancedString(string s) {
        const int LEN = s.length();
        vector<int> count(26,0);
        vector<int> cur(26,0);
        int res = LEN,left = 0;
        
        for(char c : s)
            count[c - 'A']++;
        
        for(int i = 0;i < 26;i++)
            count[i]-= min(LEN / 4,count[i]);
        
        function<bool()> check = [&]() ->bool {
            return cur['Q' - 'A'] >= count['Q' - 'A']
                && cur['W' - 'A'] >= count['W' - 'A']
                && cur['E' - 'A'] >= count['E' - 'A']
                && cur['R' - 'A'] >= count['R' - 'A'];
        };
        
        if(check())
            return 0;
        
        for(int right = 0;right < LEN;right++){
            cur[s[right] - 'A']++;
            while(left <= right && check()){
                cur[s[left++] - 'A']--;
                res = min(res,right - left + 2);
            }
        }
        
        return res;
    }
};
/*
we can replace a substring with at lease extra of those characters.
It may contain some characters that is good or less than n / 4.
*/
// 