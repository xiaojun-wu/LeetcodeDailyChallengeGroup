class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        const int SIZE = nums.size();
        Trie *trie = new Trie();
        int res = 0;
        trie->insert(nums[0]);
        
        for(int i = 1;i < SIZE;i++){
            res = max(res,trie->find(nums[i]));
            trie->insert(nums[i]);
        }
        
        return res;
    }
private:
    struct TrieNode{
        TrieNode *left, *right;
        TrieNode() : left(nullptr), right(nullptr){}
    };
    class Trie{
        public:
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode *cur = root;
            for(int i = 31;i >= 0;i--){
                bool n = (num >> i) & 1;
                if(n){
                    if(cur->right == nullptr)
                        cur->right = new TrieNode();
                    cur = cur->right;
                }
                else{
                    if(cur->left == nullptr)
                        cur->left = new TrieNode();
                    cur = cur->left;
                }
            }
        }
        int find(int num){
            TrieNode *cur = root;
            int sum = 0;
            for(int i = 31;i >= 0;i--){
                bool n = (num >> i) & 1;
                if(n){
                    if(cur->left){
                        sum+= (1 << i);
                        cur = cur->left;
                    }
                    else
                        cur = cur->right;
                }
                else{
                    if(cur->right){
                        sum+= (1 << i);
                        cur = cur->right;
                    }
                    else
                        cur = cur->left;
                }
            }
            return sum;
        }
        private:
        TrieNode* root;
    };
};