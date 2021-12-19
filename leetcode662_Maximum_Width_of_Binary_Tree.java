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
    
    public int widthOfBinaryTree(TreeNode root) {
        LinkedList<TreeNode> deque = new LinkedList<>();
        deque.add(root);
        root.val = 0;
        
        while(deque.size() > 0){
            res = Math.max(res,deque.peekLast().val - deque.peekFirst().val + 1);
            int offset = deque.peekFirst().val;
            for(int i = deque.size();i > 0;i--){
                TreeNode node = deque.pollFirst();
                if(node.left != null){
                    node.left.val = node.val * 2 - offset;
                    deque.offerLast(node.left);
                }
                if(node.right != null){
                    node.right.val = node.val * 2 - offset + 1;
                    deque.offerLast(node.right);
                }
            }
        }
        
        return res;
    }
}