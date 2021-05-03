class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int SIZE = nums.size(), MOD = 1e9 + 7;
        vector<vector<int>> comb(SIZE + 1,vector<int>(SIZE + 1,0));
        vector<vector<int>> tree(SIZE + 1,vector<int>(4,0));
        int smaller = 0, larger = 0;
        
        function<void(int,int)> buildTree = [&](int parent,int node) {
            if(node == 0)
                return;
            if(node < parent){
                tree[parent][2]++;
                if(tree[parent][0] == 0)
                    tree[parent][0] = node;
                else
                    buildTree(tree[parent][0],node);
            }
            else{
                tree[parent][3]++;
                if(tree[parent][1] == 0)
                    tree[parent][1] = node;
                else
                    buildTree(tree[parent][1],node);
            }
        };
        
        for(int i = 1;i < SIZE;i++){
            buildTree(nums[0],nums[i]);
        }
        
        function<int(int,int)> getCom = [&](int n,int k) ->int {
            k = min(k,n - k);
            if(comb[n][k] != 0) return comb[n][k];
            if(k == 0) return 1;
            comb[n][k] = (getCom(n - 1,k - 1) + getCom(n - 1,k)) % MOD;
            return comb[n][k];
        };
        
        function<int(int)> dfs = [&](int node) ->int {
            if(node == 0)
                return 1;
            long val = getCom(tree[node][2] + tree[node][3],tree[node][2]);
            val = (val * dfs(tree[node][0])) % MOD;
            val = (val * dfs(tree[node][1])) % MOD;
            return val;
        };
        
        return dfs(nums[0]) - 1;
    }
};
// https://tinyurl.com/s59ae98d