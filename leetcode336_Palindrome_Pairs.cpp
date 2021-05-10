class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> map;
        
        for(int i = 0;i < words.size();i++){
            map[words[i]] = i;
        }
        
        function<bool(string &,int,int)> isPalindrome = [](string &s,int l,int r) ->bool {
            while(l < r)
                if(s[l++] != s[r--])
                    return false;
            return true;
        };
        
        for(int i = 0;i < words.size();i++){
            if(words[i] == "") continue;
            string revWord = words[i];
            reverse(revWord.begin(),revWord.end());
            if(isPalindrome(words[i],0,words[i].length() - 1) && map.count("")){
                res.push_back({i,map[""]});
                res.push_back({map[""],i});
            }
            else if(map.count(revWord) && i != map[revWord])
                res.push_back({map[revWord],i});
            for(int j = 0;j < words[i].length() - 1;j++){
                revWord.pop_back();
                if(isPalindrome(words[i],0,j)){
                    if(map.count(revWord) && map[revWord] != i)
                        res.push_back({map[revWord],i});
                }
            }
            revWord = words[i];
            reverse(revWord.begin(),revWord.end());
            for(int j = words[i].length() - 1;j > 0;j--){
                revWord.erase(0,1);
                if(isPalindrome(words[i],j,words[i].length() - 1)){
                    if(map.count(revWord) && map[revWord] != i)
                        res.push_back({i,map[revWord]});
                }
            }
        }
        
        return res;
    }
};