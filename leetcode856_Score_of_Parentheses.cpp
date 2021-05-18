class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> stack;
        int res = 0;
        
        for(char c : S){
            if(c == '(')
                stack.push_back(0);
            else{
                int val = 0;
                while(!stack.empty() & stack.back() != 0){
                    val+= stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
                val = val==0?1:val*2;
                stack.push_back(val);
            }
        }
        
        while(!stack.empty()){
            res+= stack.back();
            stack.pop_back();
        }
        
        return res;
    }
};
// https://tinyurl.com/hw9dvcw4