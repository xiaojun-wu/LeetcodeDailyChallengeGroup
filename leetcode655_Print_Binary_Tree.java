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
    private List<List<String>> res;
    private int height;
    
    public List<List<String>> printTree(TreeNode root) {
        height = getHeight(root) - 1;
        int COL = (1 << (height + 1)) - 1;
        res = new ArrayList<List<String>>();
        
        for(int i = 0;i <= height;i++){
            List<String> subList = new ArrayList<>();
            for(int j = 0;j < COL;j++)
                subList.add("");
            res.add(subList);
        }
        
        buildRes(root,0,(COL - 1) / 2);
        
        return res;
    }
    public int getHeight(TreeNode node){
        if(node == null)
            return 0;
        return Math.max(getHeight(node.left),getHeight(node.right)) + 1;
    }
    public void buildRes(TreeNode node,int row,int col){
        if(node == null)
            return;
        res.get(row).set(col,Integer.toString(node.val));
        buildRes(node.left,row + 1,col - (1 << (height - row - 1)));
        buildRes(node.right,row + 1,col + (1 << (height - row - 1)));
    }
}

// https://tinyurl.com/2p9fzx75