class Solution {
public:
    int maxLength(vector<string>& arr) {
        // time complexity : O(len(arr) * 26 + 2^(len(arr)) * len(arr) * 26)
        const int SIZE = arr.size();
        vector<int> valids;
        unordered_set<int> seen;
        int res = 0;
        
        for(string word : arr){
            int state = 0;
            bool isValid = true;
            for(char c : word){
                if((state & (1 << (c - 'a'))) > 0){
                    isValid = false;
                    break;
                }
                state|= (1 << (c - 'a'));
            }
            if(isValid && !seen.count(state)){
                valids.push_back(state);
                seen.insert(state);
            }
        }
        
        for(int i = 1;i < (1 << valids.size());i++){
            int state = 0;
            bool isValid = true;
            for(int j = 0;(i >> j) > 0 && isValid;j++){
                if((i >> j & 1) == 1){
                    if((state & valids[j]) == 0)
                        state|= valids[j];
                    else
                        isValid = false;
                }
            }
            if(isValid)
                res = max(res,(int)bitset<27>(state).count());
        }
        
        return res;
    }
};