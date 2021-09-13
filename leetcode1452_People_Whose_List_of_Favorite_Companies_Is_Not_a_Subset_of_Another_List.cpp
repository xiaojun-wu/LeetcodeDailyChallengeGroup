class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        const int SIZE = favoriteCompanies.size();
        unordered_map<string,bitset<100>> mp;
        vector<int> res;
        
        for(int i = 0;i < SIZE;i++)
            for(string f : favoriteCompanies[i])
                mp[f][i] = 1;
        
        for(int i = 0;i < SIZE;i++){
            bitset<100> state;
            state.set();
            
            for(string f : favoriteCompanies[i])
                state&= mp[f];
            
            if(state.count() == 1)
                res.push_back(i);
        }
        
        return res;
    }
};