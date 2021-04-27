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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> nodes;
        vector<vector<int>> res;
        int sum = 0;
        
        function<void(TreeNode*)> dfs = [&](TreeNode *node) {
            if(node == nullptr){
                return;
            }
            nodes.push_back(node->val);
            sum+= node->val;
            if(node->left == node->right)
                if(sum == targetSum)
                    res.push_back(nodes);
            dfs(node->left);
            dfs(node->right);
            nodes.pop_back();
            sum-= node->val;
        };
        
        dfs(root);
        
        return res;
    }
};