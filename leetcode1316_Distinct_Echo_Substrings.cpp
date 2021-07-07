typedef uint64_t ULL;
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int LEN = text.length();
        vector<ULL> presum(1,0);
        vector<ULL> pow(1,1);
        const ULL BASE = 29;
        int res = 0;
        
        for(int i = 0;i < LEN;i++){
            presum.push_back(presum.back() * BASE + (ULL)(text[i] - 'a' + 1));
            pow.push_back(pow.back() * BASE);
        }
        
        for(int len = 2;len <= LEN;len+= 2){
            unordered_set<ULL> seen;
            for(int r = len - 1;r < LEN;r++){
                int l = r - len + 1;
                ULL leftVal = presum[l + len / 2] - presum[l] * pow[len / 2];
                ULL rightVal = presum[r + 1] - presum[l + len / 2] * pow[len / 2];
                ULL val = presum[r + 1] - presum[l] * pow[len];
                if(leftVal == rightVal)
                    seen.insert(val);
            }
            res+= seen.size();
        }
        
        return res;
    }
};

// https://tinyurl.com/ym6s58a7