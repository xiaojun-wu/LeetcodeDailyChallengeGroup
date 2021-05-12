class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        
        function<void(int,int)> dfs = [&](int left,int right) {
            if(left == 0 && right == 0){
                res.push_back(cur);
                return;
            }
            if(left){
                cur+= '(';
                dfs(left - 1,right);
                cur.pop_back();
            }
            if(right > left){
                cur+= ')';
                dfs(left,right - 1);
                cur.pop_back();
            }
        };
        
        dfs(n,n);
        
        return res;
    }
};