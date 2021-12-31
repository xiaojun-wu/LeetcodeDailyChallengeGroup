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
    public TreeNode deleteNode(TreeNode root, int key) {
        return dfs(root,key);
    }
    public TreeNode dfs(TreeNode node,int key){
        if(node == null)
            return null;
        if(node.val > key){
            node.left = dfs(node.left,key);
        }
        else if(node.val < key){
            node.right = dfs(node.right,key);
        }
        else{
            if(node.right == null)
                return node.left;
            TreeNode candidate = leftMost(node.right);
            candidate.left = node.left;
            return node.right;
        }
        return node;
    }
    public TreeNode leftMost(TreeNode node){
        if(node.left == null)
            return node;
        return leftMost(node.left);
    }
}

// https://tinyurl.com/tudkm6j2