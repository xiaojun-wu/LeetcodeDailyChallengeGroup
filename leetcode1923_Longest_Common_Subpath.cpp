typedef uint64_t ULL;
typedef pair<ULL,ULL> PULL;

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        const int SIZE = paths.size();
        ULL BASE1 = 1e5, BASE2 = 1e5 + 7;
        
        sort(paths.begin(),paths.end(),[](auto& lhs,auto& rhs){
            return lhs.size() < rhs.size();
        });
        
        int left = 0, right = 100000;
        
        
        function<bool(int)> checkValid = [&](int len) ->bool{
            if(len == 0)
                return true;
            map<PULL,int> mp;
            ULL HEAD1 = 1, HEAD2 = 1, hash1 = 0, hash2 = 0;
            bool isMatch = true;
            
            for(int i = 0;i < len - 1;i++){
                HEAD1*= BASE1;
                HEAD2*= BASE2;
            }
            
            for(int i = 0;i < SIZE && isMatch;i++){
                hash1 = 0, hash2 = 0;
                vector<int>& path = paths[i];
                if(path.size() < len)
                    return false;
                isMatch = false;
                
                for(int j = 0;j < path.size();j++){
                    hash1 = hash1 * BASE1 + (ULL)path[j];
                    hash2 = hash2 * BASE2 + (ULL)path[j];
                    
                    if(j >= len - 1){
                        if(i == 0){
                            mp[make_pair(hash1,hash2)] = 1;
                            isMatch = true;
                        }
                        else{
                            auto it = mp.find(make_pair(hash1,hash2));
                            if(it != mp.end() && it->second == i){
                                it->second++;
                                isMatch = true;
                            }
                        }
                        hash1-= HEAD1 * (ULL)path[j - len + 1];
                        hash2-= HEAD2 * (ULL)path[j - len + 1];
                    }
                }
            }
            
            return isMatch;
        };
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(checkValid(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }
};