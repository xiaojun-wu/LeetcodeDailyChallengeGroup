class Solution {
public:
    int minInsertions(string s) {
        int left = 0, insert = 0, LEN = s.length();
        
        for(int i = 0;i < LEN;i++){
            if(s[i] == '(')
                left++;
            else{
                if(left == 0){
                    left++;
                    insert++;
                }
                if(i + 1 < LEN && s[i + 1] == ')')
                    i++;
                else
                    insert++;
                left--;
            }
        }
        
        return insert + left * 2;
    }
};