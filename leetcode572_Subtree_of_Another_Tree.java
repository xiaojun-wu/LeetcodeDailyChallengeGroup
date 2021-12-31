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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null)
            return false;
        if(root.val == subRoot.val)
            if(isSame(root,subRoot))
                return true;
        return isSubtree(root.left,subRoot) || isSubtree(root.right,subRoot);
    }
    public boolean isSame(TreeNode node1, TreeNode node2){
        if(node1 == null || node2 == null)
            return node1 == node2;
        if(node1.val != node2.val)
            return false;
        return isSame(node1.left,node2.left) && isSame(node1.right,node2.right);
    }
}