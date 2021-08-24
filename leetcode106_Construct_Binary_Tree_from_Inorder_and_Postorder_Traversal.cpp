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
        vector<TreeNode*> stack;
        stack.push_back(new TreeNode(postorder.back()));
        TreeNode* root = stack.back(), *cur = root;
        
        for(int i = postorder.size() - 2,j = inorder.size() - 1;i >= 0;i--){
            if(cur->val != inorder[j]){
                cur->right = new TreeNode(postorder[i]);
                cur = cur->right;
                stack.push_back(cur);
            }
            else{
                while(!stack.empty() && stack.back()->val == inorder[j]){
                    cur = stack.back();
                    stack.pop_back();
                    j--;
                }
                cur->left = new TreeNode(postorder[i]);
                cur = cur->left;
                stack.push_back(cur);
            }
        }
        
        return root;
    }
};