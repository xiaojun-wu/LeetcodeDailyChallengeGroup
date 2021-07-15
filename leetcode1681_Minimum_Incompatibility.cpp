class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int SIZE = nums.size(), STATES = 1 << SIZE, GROUPSIZE = SIZE / k;
        int dp[1 << 16][16];
        memset(dp,0x7f,sizeof(dp));
        sort(nums.begin(),nums.end());
        for(int i = 0;i < SIZE;i++)
            dp[1 << i][i] = 0;
        int res = 256;
        
        for(int s = 0;s < STATES;s++){
            for(int i = 0;i < SIZE;i++){
                if((s & (1 << i)) == 0)
                    continue;
                int start = bitset<31>(s).count() % GROUPSIZE == 0?0:i + 1;
                for(int j = start;j < SIZE;j++){
                    if((s & (1 << j)) || (start != 0 && nums[j] == nums[i]))
                        continue;
                    int new_state = s | (1 << j);
                    if(start == 0)
                        dp[new_state][j] = min(dp[new_state][j],dp[s][i]);
                    else
                        dp[new_state][j] = min(dp[new_state][j],dp[s][i] + nums[j] - nums[i]);
                }
            }
        }
        
        res = *min_element(begin(dp[STATES - 1]),end(dp[STATES - 1]));
        
        return res >= 256?-1:res;
    }
};

// https://tinyurl.com/25ds8awu