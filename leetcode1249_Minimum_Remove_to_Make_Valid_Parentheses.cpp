class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int LEN = s.length();
        string res = "";
        vector<int> stack;
        unordered_set<int> toRemove;
        
        for(int i = 0;i < LEN;i++){
            if(s[i] == '(')
                stack.push_back(i);
            else if(s[i] == ')'){
                if(stack.empty())
                    toRemove.insert(i);
                else
                    stack.pop_back();
            }
        }
        
        toRemove.insert(stack.begin(),stack.end());
        
        for(int i = 0;i < LEN;i++)
            if(!toRemove.count(i))
                res+= s[i];
        
        return res;
    }
};
// https://tinyurl.com/6uv7ay7s