/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        return helper(quadTree1,quadTree2);
    }
    public Node helper(Node node1, Node node2){
        if(node1.isLeaf || node2.isLeaf){
            if((node1.isLeaf && node1.val) || (node2.isLeaf && node2.val))
                return new Node(true,true,null,null,null,null);
            if(!node1.isLeaf)
                return node1;
            return node2;
        }
        Node node = new Node(false,false,null,null,null,null);
        node.topLeft = helper(node1.topLeft,node2.topLeft);
        node.topRight = helper(node1.topRight,node2.topRight);
        node.bottomLeft = helper(node1.bottomLeft,node2.bottomLeft);
        node.bottomRight = helper(node1.bottomRight,node2.bottomRight);
        
        
        if(node.topLeft.val == node.topRight.val && node.topRight.val == node.bottomLeft.val && node.bottomLeft.val == node.bottomRight.val && node.topLeft.isLeaf && node.topRight.isLeaf && node.bottomLeft.isLeaf && node.bottomRight.isLeaf){
            node.isLeaf = true;
            node.val = node.topLeft.val;
            node.topLeft = null;
            node.topRight = null;
            node.bottomLeft = null;
            node.bottomRight = null;
        }
        return node;
    }
}