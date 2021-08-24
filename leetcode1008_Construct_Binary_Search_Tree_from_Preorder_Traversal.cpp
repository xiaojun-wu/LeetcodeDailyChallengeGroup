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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int SIZE = preorder.size();
        int idx = 0;
        
        function<TreeNode*(int,int)> dfs = [&](int left,int right) ->TreeNode* {
            if(idx == SIZE || preorder[idx] < left || preorder[idx] > right)
                return nullptr;
            TreeNode* node = new TreeNode(preorder[idx++]);
            if(idx == SIZE)
                return node;
            node->left = dfs(left,node->val);
            node->right = dfs(node->val,right);
            return node;
        };
        
        return dfs(0,1e8);
    }
};
// https://tinyurl.com/2ebp7e5z