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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr, *second = nullptr, *cur = root;
        TreeNode* pre = new TreeNode(INT_MIN);
        
        function<void()> check = [&]() {
            if(cur->val < pre->val){
                if(first == nullptr){
                    first = pre;
                    second = cur;
                }
                else
                    second = cur;
            }
        };
        
        while(cur){
            if(cur->left == nullptr){
                check();
                pre = cur;
                cur = cur->right;
            }
            else{
                TreeNode* rightMost = cur->left;
                while(rightMost->right && rightMost->right != cur)
                    rightMost = rightMost->right;
                if(rightMost->right == nullptr){
                    rightMost->right = cur;
                    cur = cur->left;
                }
                else{
                    rightMost->right = nullptr;
                    check();
                    pre = cur;
                    cur = cur->right;
                }
            }
            
        }
        swap(first->val,second->val);
        
        return;
    }
};
/*
take advantage of Morris Traversal that inorder a binary tree with O(1) space.
and we have to find two nodes that they swaped.
How to check if a node is wrong?
Because it is a binary search tree, inorder traversal always ascending.
If a node->val is smaller than previous node->val, it is swaped.
*/
// https://tinyurl.com/pdu35zem