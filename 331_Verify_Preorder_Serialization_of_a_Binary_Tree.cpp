class Solution {
public:
    bool isValidSerialization(string preorder) {
        const int LEN = preorder.length();
        int n = 1, idx = 0;
        while(idx < LEN && n > 0){
            size_t comma = preorder.find(',',idx);
            if(comma == string::npos)
                comma = preorder.size();
            if(comma > idx + 1 || preorder[idx] != '#')
                n+= 2;
            n--;
            idx = comma + 1;
        }
        
        return n == 0 && idx == LEN + 1;
    }
};