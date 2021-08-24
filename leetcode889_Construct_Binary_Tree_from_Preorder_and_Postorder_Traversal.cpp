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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int SIZE = preorder.size();
        vector<int> mp(31,0);
        for(int i = 0;i < postorder.size();i++)
            mp[postorder[i]] = i;
        
        function<TreeNode*(int,int,int,int)> dfs = [&](int preleft,int preright,int postleft,int postright) ->TreeNode* {
            if(preleft > preright)
                return nullptr;
            TreeNode* node = new TreeNode(preorder[preleft++]);
            if(preleft > preright)
                return node;
            int idx = mp[preorder[preleft]];
            node->left = dfs(preleft,preleft + (idx - postleft),postleft,idx);
            node->right = dfs(preleft + (idx - postleft) + 1,preright,idx + 1,postright - 1);
            return node;
        };
        
        return dfs(0,SIZE - 1,0,SIZE - 1);
    }
};
// https://tinyurl.com/chub65yx