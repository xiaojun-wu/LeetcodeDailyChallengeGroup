class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        /*
        brute force with pruning, tc: O(2^N), sc: O(N).
        */
        const int LEN = s.length();
        string cur = "";
        int left = 0,right = 0, resLen = LEN;
        vector<int> sufLeft(LEN + 1,0), sufRight(LEN + 1,0);
        unordered_set<string> res;
        
        
        for(int i = LEN - 1;i >= 0;i--){
            if(s[i] == '(')
                sufLeft[i]++;
            else if(s[i] == ')')
                sufRight[i]++;
            sufLeft[i]+= sufLeft[i + 1];
            sufRight[i]+= sufRight[i + 1];
        }
        
        for(char c : s){
            if(c == '(')
                left++;
            else if(c == ')'){
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }
        
        resLen-= left + right;
        
        if(resLen == LEN)
            return {s};
        
        function<bool()> isValid = [&]() {
            if(cur.length() != resLen)
                return false;
            int l = 0,r = 0;
            for(char c : cur){
                if(c == '(')
                    l++;
                else if(c == ')'){
                    if(l == 0)
                        return false;
                    l--;
                }
            }
            return l == 0;
        };
        
        function<void(int,int,int)> dfs = [&](int idx,int l,int r) {
            if(idx == LEN){
                if(isValid())
                    res.insert(cur);
                return;
            }
            if(s[idx] != '(' && s[idx] != ')'){
                cur+= s[idx];
                dfs(idx + 1,l,r);
                return cur.pop_back();;
            }
            if(s[idx] == '('){
                if(l == 0 || sufLeft[idx + 1] >= l){
                    cur+= s[idx];
                    dfs(idx + 1,l,r);
                    cur.pop_back();
                }
                if(l > 0)
                    return dfs(idx + 1,l - 1,r);
            }
            else{
                if(r == 0 || sufRight[idx + 1] >= r){
                    cur+= s[idx];
                    dfs(idx + 1,l,r);
                    cur.pop_back();
                }
                if(r > 0)
                    return dfs(idx + 1,l,r - 1);
            }
            return;
        };
        
        dfs(0,left,right);
        
        return vector<string>(res.begin(),res.end());
    }
};
// https://tinyurl.com/pths6h3w