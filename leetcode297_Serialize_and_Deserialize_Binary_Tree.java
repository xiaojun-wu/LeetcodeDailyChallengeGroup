/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null)
            return "";
        LinkedList<TreeNode> deque = new LinkedList<>();
        deque.offer(root);
        StringBuilder sb = new StringBuilder();
        
        while(deque.size() > 0){
            for(int i = deque.size();i > 0;i--){
                TreeNode node = deque.pollFirst();
                if(node != null)
                    sb.append(Integer.toString(node.val) + ",");
                else
                    sb.append("null,");
                if(node != null)
                    deque.offerLast(node.left);
                if(node != null)
                    deque.offerLast(node.right);
            }
        }
        sb.delete(sb.length() - 1,sb.length());
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.equals(""))
            return null;
        String nodes[] = data.split(",");
        LinkedList<TreeNode> list = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));
        list.add(root);
        int idx = 0, idx2 = 1;
        while(idx < list.size()){
            TreeNode node = null;
            if(!nodes[idx2].equals("null")){
                node = new TreeNode(Integer.parseInt(nodes[idx2]));
            }
            list.get(idx).left = node;
            idx2++;
            if(node != null)
                list.add(node);
            node = null;
            if(!nodes[idx2].equals("null")){
                node = new TreeNode(Integer.parseInt(nodes[idx2]));
            }
            list.get(idx).right = node;
            idx2++;
            if(node != null)
                list.add(node);
            idx++;
        }
        
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));

