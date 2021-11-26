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
    private HashMap<Long,Long> idMap;
    private HashMap<Long,Long> counter;
    private List<TreeNode> res;
    private long id;
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        res = new ArrayList<>();
        idMap = new HashMap<>();
        counter = new HashMap<>();
        id = 2;
        
        dfs(root);
        
        return res;
    }
    
    public long dfs(TreeNode node){
        if(node == null)
            return 1;
        long leftId = dfs(node.left);
        long rightId = dfs(node.right);
        long curVal = ((long)node.val) * 100000000 + leftId * 10000 + rightId;
        long curId = id;
        if(idMap.containsKey(curVal)){
            curId = idMap.get(curVal);
            counter.put(curVal,counter.getOrDefault(curVal,0l) + 1l);
            if(counter.get(curVal) == 2){
                res.add(node);
            }
        }
        else{
            id++;
            idMap.put(curVal,curId);
            counter.put(curVal,1l);
        }
        return curId;
    }
}

// https://tinyurl.com/3ybrwvzf