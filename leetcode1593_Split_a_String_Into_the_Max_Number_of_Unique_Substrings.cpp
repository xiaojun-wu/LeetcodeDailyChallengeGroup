class Solution {
public:
    int maxUniqueSplit(string s) {
        /*
        backtracking + binary search.
        */
        const int LEN = s.length();
        unordered_set<string> seen;
        
        function<bool(int,int)> dfs = [&](int idx,int n) ->bool {
            if(idx == LEN || n == 0)
                return idx == LEN && n == 0;
            string cur = "";
            for(int i = idx;i < LEN - n + 1;i++){
                cur+= s[i];
                auto p = seen.insert(cur);
                if(p.second){
                    if(dfs(i + 1,n - 1))
                        return true;
                    seen.erase(p.first);
                }
            }
            return false;
        };
        
        int left = 1, right = LEN;
        while(left <= right){
            int mid = left + (right - left) / 2;
            seen.clear();
            if(dfs(0,mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }
};