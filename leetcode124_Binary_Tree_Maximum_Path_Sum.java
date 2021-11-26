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
    private int res = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        dfs(root);
        return res;
    }
    public int dfs(TreeNode root){
        if(root == null)
            return 0;
        int leftSum = dfs(root.left);
        int rightSum = dfs(root.right);
        res = Math.max(res,leftSum + rightSum + root.val);
        res = Math.max(res,leftSum + root.val);
        res = Math.max(res,rightSum + root.val);
        res = Math.max(res,root.val);
        return root.val + Math.max(Math.max(leftSum,rightSum),0);
    }
}