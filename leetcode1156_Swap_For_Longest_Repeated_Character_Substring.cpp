class Solution {
public:
    int maxRepOpt1(string text) {
        const int LEN = text.length();
        vector<int> counts(26,0);
        vector<pair<char,int>> groups;
        int res = 0;
        
        for(int i = 0;i < LEN;i++){
            char cur = text[i];
            int j = i;
            while(j < LEN && text[j] == cur)j++;
            groups.emplace_back(cur,j - i);
            counts[cur - 'a']++;
            i = j - 1;
        }
        groups.emplace_back('@',1);
        
        for(int i = 1;i < groups.size();i++){
            int extra1 = min(1,counts[groups[i - 1].first - 'a'] - 2);
            int extra2 = min(1,counts[groups[i - 1].first - 'a'] - 1);
            if(groups[i].second == 1 && i < groups.size() - 1 && groups[i + 1].first == groups[i - 1].first)
                res = max(res,groups[i - 1].second + groups[i + 1].second + extra1);
            res = max(res,groups[i - 1].second + extra2);
        }
        
        return res;
    }
};