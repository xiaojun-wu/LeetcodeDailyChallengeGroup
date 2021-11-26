class Solution {
    private int total = 0;
    private List<List<Integer>> graph;
    private List<List<Long>> subtrees;
    public int countHighestScoreNodes(int[] parents) {
        final int SIZE = parents.length;
        graph = new ArrayList<List<Integer>>();
        subtrees = new ArrayList<List<Long>>();
        int res = 0;
        long highest = Long.MIN_VALUE;
        
        for(int i = 0;i < SIZE;i++){
            graph.add(new ArrayList<Integer>());
            subtrees.add(new ArrayList<Long>());
        }
        
        for(int i = 0;i < SIZE;i++)
            if(parents[i] != -1)
                graph.get(parents[i]).add(i);
        
        dfs(0);
        
        for(int i = 0;i < SIZE;i++){
            long cur = 1, rest = total - 1;
            for(Long n : subtrees.get(i)){
                rest-= n;
                cur*= n;
            }
            if(rest > 0)
                cur*= rest;
            if(cur > highest){
                highest = cur;
                res = 1;
            }
            else if(cur == highest){
                res++;
            }
        }
        
        return res;
    }
    public int dfs(int idx){
        this.total++;
        if(graph.get(idx).size() == 0)
            return 1;
        int totalSize = 1;
        for(int i = 0;i < graph.get(idx).size();i++){
            int size = dfs(graph.get(idx).get(i));
            totalSize+= size;
            if(size != 0)
                subtrees.get(idx).add(((long)size));
        }
        return totalSize;
    }
}