class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        const int SIZE = arr.size();
        unordered_map<int,int> mp;
        
        for(int n : arr) mp[n]++;
        
        sort(arr.begin(),arr.end(),[](int lhs,int rhs){
            return abs(lhs) < abs(rhs);
        });
        
        for(int n : arr){
            if(mp[n] == 0) continue;
            if(mp[n] > mp[n * 2])
                return false;
            mp[n * 2]-= mp[n];
            mp[n] = 0;
        }
        
        return true;
    }
};