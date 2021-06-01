class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        /*
        greedy + sort
        TC: O(NlogN), SC: O(N)
        */
        const int SIZE = inventory.size(), MOD = 1e9 + 7;
        sort(inventory.begin(),inventory.end(),greater<int>());
        inventory.push_back(0);
        int res = 0;
        
        function<long(long,long)> getProfit = [&](long h,long l) ->long {
            return (h * (h + 1) / 2) - (l * (l + 1) / 2);
        };
        
        for(long i = 0;i < SIZE && orders > 0;i++){
            if((long)(inventory[i] - inventory[i + 1]) * (i + 1) <= orders){
                res = (res + getProfit(inventory[i],inventory[i + 1]) * (i + 1)) % MOD;
                orders-= (inventory[i] - inventory[i + 1]) * (i + 1);
            }
            else{
                long level = orders / (i + 1), rest = orders % (i + 1);
                res = (res + getProfit(inventory[i],inventory[i] - level) * (i + 1)) % MOD;
                res = (res + rest * (inventory[i] - level)) % MOD;
                orders = 0;
            }
        }
        
        return res;
    }
};
// https://tinyurl.com/kdfkv3k7