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
    int longestUnivaluePath(TreeNode* root) {
        // left + root + right.
        int res = 0;
        
        function<int(TreeNode*,int)> dfs = [&](TreeNode *node,int preVal) ->int {
            if(node == nullptr)
                return 0;
            int leftLen = dfs(node->left,node->val), rightLen = dfs(node->right,node->val);
            res = max(res,leftLen + rightLen);
            if(node->val == preVal)
                return 1 + max(leftLen,rightLen);
            return 0;
        };
        
        dfs(root,-10000);
        
        return res;
    }
};
/*

*/