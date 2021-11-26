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
    private int res;
    public int longestUnivaluePath(TreeNode root) {
        if(root == null)
            return 0;
        this.res = 0;
        dfs(root);
        return res - 1;
    }
    private int dfs(TreeNode node){
        if(node == null)
            return 0;
        int leftLen = dfs(node.left);
        int rightLen = dfs(node.right);
        if(node.left != null && node.left.val != node.val)
            leftLen = 0;
        if(node.right != null && node.right.val != node.val)
            rightLen = 0;
        res = Math.max(res,leftLen + rightLen + 1);
        // System.out.println("val : " + node.val + ", leftLen : " + leftLen + ", rightLen : " + rightLen + ", res : " + res);
        return Math.max(leftLen,rightLen) + 1;
    }
}

// https://tinyurl.com/5mu8zy5p