class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const int SIZE = word.length();
        int res = 0;
        char pre = 'a';
        vector<int> mp(26,'#');
        mp['e' - 'a'] = 'a';
        mp['i' - 'a'] = 'e';
        mp['o' - 'a'] = 'i';
        mp['u' - 'a'] = 'o';
        
        for(int i = 0;i < SIZE;i++){
            if(word[i] == 'a'){
                int idx = i;
                while(true){
                    while(idx < SIZE && word[idx] == pre) idx++;
                    if(idx == SIZE) break;
                    if(mp[word[idx] - 'a'] != pre)
                        break;
                    pre = word[idx];
                }
                if(pre == 'u')
                    res = max(res,idx - i);
                i = idx - 1;
                pre = 'a';
            }
        }
        
        return res;
    }
};