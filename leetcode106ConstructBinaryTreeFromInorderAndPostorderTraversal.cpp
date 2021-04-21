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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // TC:O(N), SC:O(H + 6001);
        const int SIZE = inorder.size();
        vector<int> mp(6001,0);
        for(int i = 0;i < SIZE;i++)
            mp[inorder[i] + 3000] = i;
        
        function<TreeNode*(int,int,int)> dfs = [&](int left,int right,int back) ->TreeNode* {
            if(left > right)
                return nullptr;
            if(left == right)
                return new TreeNode(inorder[left]);
            TreeNode *root = new TreeNode(postorder[back]);
            int rootIdx = mp[postorder[back] + 3000];
            int leftLen = rootIdx - left,rightLen = right - rootIdx;
            root->left = dfs(left,rootIdx - 1,back - rightLen - 1);
            root->right = dfs(rootIdx + 1,right,back - 1);
            return root;
        };
        
        return dfs(0,SIZE - 1,SIZE - 1);
    }
};
/*
inorder : left root right
postorder : left right root
*/