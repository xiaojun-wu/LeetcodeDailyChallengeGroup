/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        
        function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            if(node == nullptr)
                return;
            sum+= node->val;
            if(mp.count(sum - targetSum))
                res+= mp[sum - targetSum];
            mp[sum]++;
            dfs(node->left);
            dfs(node->right);
            mp[sum]--;
            if(mp[sum] == 0)
                mp.erase(sum);
            sum-= node->val;
        };
        
        dfs(root);
        
        return res;
    }
};