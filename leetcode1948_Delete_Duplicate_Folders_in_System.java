class Solution {
    private HashMap<String,Integer> pathMap;
    private HashMap<String,Integer> idMap;
    private HashMap<Integer,Integer> counter;
    private List<List<String>> res;
    
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        pathMap = new HashMap<>();
        idMap = new HashMap<>();
        counter = new HashMap<>();
        res = new ArrayList<List<String>>();
        
        TreeNode root = new TreeNode("");
        
        for(List<String> path : paths){
            buildTree(path,0,root);
        }
        
        dfs(root);
        
        checkNodes(root,new ArrayList<String>());
        
        return res;
    }
    public void buildTree(List<String> list,int idx,TreeNode node){
        if(idx == list.size())
            return;
        String val = list.get(idx);
        TreeNode next = node.getChild(val);
        if(next == null)
            next = node.addChild(val);
        buildTree(list,idx + 1,next);
    }
    public int dfs(TreeNode node){
        if(node == null)
            return 1;
        String val = node.getVal();
        List<Integer> ids = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        
        for(Map.Entry<String,TreeNode> entry : node.getEntrySet()){
            ids.add(dfs(entry.getValue()));
        }
        
        Collections.sort(ids);
        
        for(int n : ids)
            sb.append(Integer.toString(n) + ",");
        
        String value = sb.toString();
        int id = -1;
        
        if(idMap.containsKey(value)){
            id = idMap.get(value);
            counter.put(id,counter.get(id) + 1);
            node.setId(id);
        }
        else{
            id = idMap.size() + 2;
            idMap.put(value,id);
            counter.put(id,1);
            node.setId(id);
        }
        
        value = val + "," + value;
        
        if(idMap.containsKey(value)){
            id = idMap.get(value);
            counter.put(id,counter.get(id) + 1);
        }
        else{
            id = idMap.size() + 2;
            idMap.put(value,id);
            counter.put(id,1);
        }
        
        return id;
    }
    public void checkNodes(TreeNode node,List<String> list){
        if(node == null)
            return;
        
        if(counter.get(node.getId()) > 1 && node.getId() != 2)
            return;
        
        if(!node.getVal().equals(""))
            list.add(node.getVal());
        if(list.size() > 0){
            List<String> cur = new ArrayList<>();
            list.forEach(e -> cur.add(e));
            this.res.add(cur);
        }
        
        for(Map.Entry<String,TreeNode> entry : node.getEntrySet())
            checkNodes(entry.getValue(),list);
        if(list.size() > 0)
            list.remove(list.size() - 1);
    }
}
class TreeNode{
    private HashMap<String,TreeNode> childern;
    private String val;
    private int id;
    
    public TreeNode(String val){
        this.val = val;
        this.childern = new HashMap<>();
        this.id = -1;
    }
    public boolean isChild(String s){
        return this.childern.containsKey(s);
    }
    public TreeNode getChild(String s){
        return this.childern.getOrDefault(s,null);
    }
    public TreeNode addChild(String s){
        TreeNode child = new TreeNode(s);
        childern.put(s,child);
        return child;
    }
    public String getVal(){
        return this.val;
    }
    public Set<Map.Entry<String,TreeNode>> getEntrySet(){
        return this.childern.entrySet();
    }
    public void setId(int id){
        this.id = id;
    }
    public int getId(){
        return this.id;
    }
}