class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        const int LEN = s.length();
        int n = k - repetition;
        vector<int> counts(LEN + 1,0);
        string stack = "";
        string res = "";
        int count = 0;
        
        for(int i = LEN - 1;i >= 0;i--){
            if(s[i] == letter)
                counts[i]++;
            counts[i]+= counts[i + 1];
        }
        
        for(int i = 0;i < LEN;i++){
            while(!stack.empty() && stack.back() > s[i]){
                if(stack.back() == letter && count + counts[i] == repetition)
                    break;
                if(stack.size() + (LEN - i) == k)
                    break;
                if(stack.back() == letter)
                    count--;
                stack.pop_back();
            }
            stack.push_back(s[i]);
            if(s[i] == letter)
                count++;
        }
        
        count = 0;
        for(char c : stack){
            if(c != letter && (k - res.size() == repetition - count))
                continue;
            res+= c;
            if(c == letter)
                count++;
            if(res.size() == k)
                break;
        }
        
        return res;
    }
};
