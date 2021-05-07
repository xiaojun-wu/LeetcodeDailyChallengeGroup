/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = nullptr;
        
        function<bool(TreeNode*)> dfs = [&](TreeNode *node) ->bool{
            if(node == nullptr)
                return false;
            bool leftHas = dfs(node->left);
            bool rightHas = dfs(node->right);
            if(((node == p || node == q) && (leftHas || rightHas)) || (leftHas && rightHas)){
                res = node;
                return false;
            }
            
            return leftHas || rightHas || node == p || node == q;
        };
        
        dfs(root);
        
        return res;
    }
};
// https://tinyurl.com/nhmnxzym