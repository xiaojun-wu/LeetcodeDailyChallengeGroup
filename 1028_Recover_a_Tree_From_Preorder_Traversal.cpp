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
    TreeNode* recoverFromPreorder(string S) {
        const int LEN = S.length();
        int nextDepth = 0, idx = 0;
        
        function<TreeNode*(int)> dfs = [&](int depth) {
            string n = "";
            while(idx < LEN && S[idx] != '-')
                n+= S[idx++];
            TreeNode *cur = new TreeNode(stoi(n));
            int temp = 0;
            while(idx < LEN && S[idx] == '-'){
                idx++;
                temp++;
            }
            nextDepth = temp;
            if(nextDepth == depth + 1)
                cur->left = dfs(depth + 1);
            if(nextDepth == depth + 1)
                cur->right = dfs(depth + 1);
            return cur;
        };
        
        return dfs(0);
    }
};