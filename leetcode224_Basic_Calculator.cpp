class Solution {
public:
    int idx = 0;
    int calculate(string s) {
        string ns = "";
        int res = 0;
        for(char c : s)
            if(c != ' ')
                ns+= c;
        return term(ns);
    }
    int term(string& s){
        if(idx == s.length())
            return 0;
        int sum = getNum(s);
        while(idx < s.length() && s[idx] != ')'){
            char op = getOp(s);
            int n = getNum(s);
            if(op == '+') sum+= n;
            else sum-= n;
        }
        if(idx < s.length() && s[idx] == ')') idx++;
        // cout<<sum<<" "<<idx<<" "<<s[idx]<<endl;
        return sum;
    }
    int term2(string& s){
        idx++;
        int sum = getNum(s);
        while(idx < s.length() && s[idx] != ')'){
            char op = getOp(s);
            int n = getNum(s);
            if(op == '+') sum+= n;
            else sum-= n;
        }
        idx++;
        return sum;
    }
    int getNum(string& s){
        if(s[idx] == '(')
            return term2(s);
        bool flag = true;
        string t = "";
        while(idx < s.length() && !('0' <= s[idx] && s[idx] <= '9') && s[idx] != '(')
            if(s[idx++] == '-')
                flag = !flag;
        if(s[idx] == '(')
            return flag?term2(s):-term2(s);
        while(idx < s.length() && '0' <= s[idx] && s[idx] <= '9')
            t+= s[idx++];
        int n = stoi(t);
        
        return flag?n:-n;
    }
    char getOp(string& s){
        return s[idx++];
    }
};