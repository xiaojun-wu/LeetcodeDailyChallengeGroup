class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int SIZE = A.size();
        vector<unordered_map<long,long>> dp(SIZE,unordered_map<long,long>());
        int res = 0;
        
        for(int i = 0;i < SIZE;i++){
            for(int j = i - 1;j >= 0;j--){
                long diff = (long)(A[i]) - (long)(A[j]);
                auto it = dp[j].find(diff);
                if(it != dp[j].end()){
                    dp[i][diff]+= it->second;
                    res+= it->second;
                }
                dp[i][diff]++;
            }
        }
        
        return res;
    }
};