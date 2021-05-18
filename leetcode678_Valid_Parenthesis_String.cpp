class Solution {
public:
    bool checkValidString(string s) {
        // two pointers, two pass.
        int left = 0, right = 0, star = 0;
        for(char c : s){
            if(c == '(')
                left++;
            else if(c == '*')
                star++;
            else{
                if(left + star < right + 1)
                    return false;
                right++;
            }
        }
        
        if(left > star + right)
            return false;
        
        left = 0, right = 0, star = 0;
        
        for(int i = s.length() - 1;i >= 0;i--){
            if(s[i] == ')')
                right++;
            else if(s[i] == '*')
                star++;
            else{
                if(right + star < left + 1)
                    return false;
                left++;
            }
        }
        
        return left <= star + right;
    }
};