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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        const int SIZE = voyage.size();
        vector<int> res, f(1,-1);
        int idx = 0;
        
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) ->bool {
            if(node == nullptr)
                return true;
            if(idx == SIZE || node->val != voyage[idx])
                return false;
            if(node->left && idx + 1 < SIZE && node->left->val != voyage[idx + 1]){
                swap(node->left,node->right);
                res.push_back(node->val);
            }
            idx++;
            return dfs(node->left) && dfs(node->right);
        };
        
        return dfs(root)?res:f;
    }
};