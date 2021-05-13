class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int SIZE = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        
        function<void(int,int)> dfs = [&](int idx,int n) {
            if(n == 0){
                res.push_back(cur);
                return;
            }
            if(idx == SIZE)
                return;
            int pre = -11;
            for(int i = idx;i < SIZE;i++){
                if(nums[i] == pre)
                    continue;
                cur.push_back(nums[i]);
                dfs(i + 1,n - 1);
                pre = nums[i];
                cur.pop_back();
            }
        };
        
        for(int i = 0;i <= SIZE;i++)
            dfs(0,i);
        
        return res;
    }
};
// https://tinyurl.com/nft2hu6u