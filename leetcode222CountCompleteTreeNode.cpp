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
    int countNodes(TreeNode* root) {
        // binary search.
        if(root == nullptr)
            return 0;
        TreeNode *cur = root;
        int h = -1;
        while(cur){
            h++;
            cur = cur->left;
        }
        int left = 0, right = pow(2,h) - 1;
        while(left <= right){
            int mid = left + (right - left) / 2, ch = 0, val = 0;
            cur = root;
            while(cur && ch < h){
                if(cur->right && val + pow(2,h - ch - 1) <= mid){
                    val+= pow(2,h - ch - 1);
                    cur = cur->right;
                }
                else if(cur->left){
                    cur = cur->left;
                }
                else
                    break;
                ch++;
            }
            if(ch == h && val >= mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return pow(2,h) + right;
    }
};