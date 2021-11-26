/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return res;
    }
    public int dfs(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftLen = dfs(root.left);
        int rightLen = dfs(root.right);
        res = Math.max(res,leftLen + rightLen);
        return Math.max(leftLen,rightLen) + 1;
    }
}