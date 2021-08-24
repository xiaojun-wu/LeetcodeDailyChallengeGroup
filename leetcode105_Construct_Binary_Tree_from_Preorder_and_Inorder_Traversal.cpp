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
        const int SIZE = preorder.size();
        vector<TreeNode*> stack;
        stack.push_back(new TreeNode(preorder[0]));
        TreeNode* cur = stack.back(), *root = cur;
        
        for(int i = 1,j = 0;i < preorder.size();i++){
            if(cur->val != inorder[j]){
                cur->left = new TreeNode(preorder[i]);
                cur = cur->left;
                stack.push_back(cur);
            }
            else{
                while(!stack.empty() && stack.back()->val == inorder[j]){
                    cur = stack.back();
                    stack.pop_back();
                    j++;
                }
                cur->right = new TreeNode(preorder[i]);
                cur = cur->right;
                stack.push_back(cur);
            }
        }
        
        return root;
    }
};

//https://tinyurl.com/2uks3zha