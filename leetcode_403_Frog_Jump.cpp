class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int SIZE = stones.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < SIZE;i++){
            mp[stones[i]] = i;
        }
        if(!mp.count(1)){
            return false;
        }
        vector<unordered_set<int>> dp(SIZE,unordered_set<int>());
        dp[1].insert(1);

        for(int i = 1;i < SIZE && dp.back().empty();i++){
            for(int k : dp[i]){
                if(k - 1 > 0 && mp.count(stones[i] + k - 1)){
                    dp[mp[stones[i] + k - 1]].insert(k - 1);
                }
                if(mp.count(stones[i] + k)){
                    dp[mp[stones[i] + k]].insert(k);
                }
                if(mp.count(stones[i] + k + 1)){
                    dp[mp[stones[i] + k + 1]].insert(k + 1);
                }
            }
        }

        return !dp.back().empty();
    }
};