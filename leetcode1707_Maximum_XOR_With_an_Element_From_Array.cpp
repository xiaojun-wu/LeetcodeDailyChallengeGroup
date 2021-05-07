class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        const int SIZE1 = nums.size(), SIZE2 = queries.size();
        for(int i = 0;i < queries.size();i++)
            queries[i].push_back(i);
        
        sort(queries.begin(),queries.end(),[](auto& lhs,auto& rhs){
            return lhs[1] < rhs[1];
        });
        sort(nums.begin(),nums.end());
        vector<int> res(queries.size(),-1);
        root = new TrieNode();
        
        for(int i = 0,j = 0;i < SIZE2;i++){
            while(j < SIZE1 && nums[j] <= queries[i][1])
                insert(nums[j++]);
            res[queries[i][2]] = find(queries[i][0]);
        }
        
        return res;
    }
private:
    struct TrieNode{
        TrieNode* children[2];
        TrieNode(){
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };
    TrieNode *root;
    void insert(int n){
        TrieNode *cur = root;
        for(int i = 30;i >= 0;i--){
            int b = (n >> i) & 1;
            if(cur->children[b] == nullptr)
                cur->children[b] = new TrieNode();
            cur = cur->children[b];
        }
    }
    int find(int n){
        int sum = 0;
        TrieNode *cur = root;
        if(cur->children[0] == cur->children[1])
            return -1;
        for(int i = 30;i >= 0;i--){
            int b = (n >> i) & 1;
            if(cur->children[!b]){
                sum+= (1 << i);
                cur = cur->children[!b];
            }
            else
                cur = cur->children[b];
        }
        return sum;
    }
};