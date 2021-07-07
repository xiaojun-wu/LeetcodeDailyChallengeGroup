typedef uint64_t ULL;
typedef pair<ULL,ULL> PULL;

class Solution {
public:
    string longestDupSubstring(string s) {
        ULL BASE1 = 1e5 +3, BASE2 = 1e5 + 19;
        const int LEN = s.length();
        string res = "";
        int left = 1, right = LEN - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            // double hash using treeset.
//             set<PULL> seen;
//             ULL HEAD1 = 1, HEAD2 = 1, hash1 = 0, hash2 = 0;
//             bool isFound = false;
            
//             for(int i = 0;i < mid - 1;i++){
//                 HEAD1*= BASE1;
//                 HEAD2*= BASE2;
//             }
            
//             for(int i = 0;i < LEN && !isFound;i++){
//                 hash1 = hash1 * BASE1 + (ULL)(s[i] - 'a');
//                 hash2 = hash2 * BASE2 + (ULL)(s[i] - 'a');
                
//                 if(i >= mid - 1){
//                     // cout<<mid<<" "<<i<<" "<<hash1<<" "<<hash2<<endl;
//                     auto p = seen.insert({hash1,hash2});
//                     if(!p.second){
//                         res = s.substr(i - mid + 1,mid);
//                         isFound = true;
//                     }
//                     hash1-= HEAD1 * (ULL)(s[i - mid + 1] - 'a');
//                     hash2-= HEAD2 * (ULL)(s[i - mid + 1] - 'a');
//                 }
//             }
            
            
            // single hash using hashset.
            unordered_set<ULL> seen;
            ULL HEAD = 1, hash = 0;
            bool isFound = false;
            
            for(int i = 0;i < mid - 1;i++)
                HEAD*= BASE1;
            
            for(int i = 0;i < LEN && !isFound;i++){
                hash = hash * BASE1 + (ULL)(s[i] - 'a');
                
                if(i >= mid - 1){
                    auto p = seen.insert(hash);
                    if(!p.second){
                        res = s.substr(i - mid + 1,mid);
                        isFound = true;
                    }
                    hash-= HEAD * (ULL)(s[i - mid + 1] - 'a');
                }
            }
            
            if(isFound)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return res;
    }
};
