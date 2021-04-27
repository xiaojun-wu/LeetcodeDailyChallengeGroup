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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TC:O(N), SC:O(H + 6001)
        const int SIZE = preorder.size();
        vector<int> mp(6001,0);
        for(int i = 0;i < inorder.size();i++)
            mp[inorder[i] + 3000] = i;
        
        function<TreeNode*(int,int,int,int)> dfs = [&](int preleft,int preright,int inleft,int inright) ->TreeNode* {
            if(inleft > inright)
                return nullptr;
            if(preleft == preright)
                return new TreeNode(preorder[preleft]);
            int rootIdx = mp[preorder[preleft] + 3000];
            int leftLen = rootIdx - inleft;
            TreeNode *rootNode = new TreeNode(preorder[preleft]);
            rootNode->left = dfs(preleft + 1,preleft + leftLen,inleft,inleft + leftLen - 1);
            rootNode->right = dfs(preleft + 1 + leftLen,preright,inleft + 1 + leftLen,inright);
            return rootNode;
        };
        
        return dfs(0,SIZE - 1,0,SIZE - 1);
    }
};
/*
preorder : root left right
inorder : left root right
*/