class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int LEN = s.length();
        vector<int> lastIdx(26,-1);
        vector<int> beginIdx(26,-1);
        vector<string> res;
        vector<pair<int,int>> ps;
        vector<int> first, last;
        
        for(int i = 0;i < LEN;i++)
            lastIdx[s[i] - 'a'] = i;
        for(int i = LEN - 1;i >= 0;i--)
            beginIdx[s[i] - 'a'] = i;
        
        function<void(int)> check = [&](int idx) {
            int right = last.back(), left = right;
            last.pop_back();
            while(!first.empty() && first.size() > last.size()){
                left = first.back();
                first.pop_back();
            }
            if(ps.empty() || left > ps.back().second)
                ps.emplace_back(left,right);
        };
        
        for(int i = 0;i < LEN;i++){
            if(!last.empty() && last.back() < i){
                check(i);
            }
            while(!first.empty() && first.back() > beginIdx[s[i] - 'a'])
                first.pop_back();
            if(i == beginIdx[s[i] - 'a'])
                first.push_back(beginIdx[s[i] - 'a']);
            while(!last.empty() && last.back() < lastIdx[s[i] - 'a'])
                last.pop_back();
            if(i == beginIdx[s[i] - 'a'])
                last.push_back(lastIdx[s[i] - 'a']);
            while(first.size() != last.size()){
                if(first.size() > last.size())
                    first.pop_back();
                else
                    last.pop_back();
            }
        }
        
        check(LEN);
        
        for(auto[l,r] : ps)
            res.push_back(s.substr(l,r - l + 1));
        
        return res;
    }
};
/*
case 1. characters in substring are same.
case 2. contains two or more characters in substring.
*/
// https://tinyurl.com/kf38srtf