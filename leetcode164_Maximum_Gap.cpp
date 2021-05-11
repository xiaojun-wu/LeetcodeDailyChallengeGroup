class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // bucket sort.
        const int SIZE = nums.size();
        if(SIZE < 2)
            return 0;
        
        vector<int> sortedIndice;
        vector<vector<int>> bucket(10,vector<int>());
        vector<string> snums;
        int res = 0;
        
        for(int n : nums)
            snums.push_back(to_string(n));
        
        for(int i = 0;i < SIZE;i++)
            bucket[snums[i].back() - '0'].push_back(i);
        
        for(int i = 0;i <= 10;i++){
            vector<vector<int>> next(10,vector<int>());
            for(int j = 0;j < 10;j++){
                for(int k : bucket[j]){
                    if(snums[k].length() == 1)
                        sortedIndice.push_back(k);
                    snums[k].pop_back();
                    if(!snums[k].empty())
                        next[snums[k].back() - '0'].push_back(k);
                }
            }
            swap(next,bucket);
        }
        
        for(int i = 0;i < SIZE - 1;i++)
            res = max(res,nums[sortedIndice[i + 1]] - nums[sortedIndice[i]]);
        
        return res;
    }
};
// https://tinyurl.com/5abrevry