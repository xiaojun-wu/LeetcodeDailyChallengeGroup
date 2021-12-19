class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        int visited[] = new int[n];
        List<List<Integer>> adj = new ArrayList<List<Integer>>();
        int indegrees[] = new int[n];
        List<Integer> deque = new LinkedList<>();
        
        for(int i = 0;i < n;i++)
            adj.add(new ArrayList<Integer>());
        
        for(int i = 0;i < edges.length;i++){
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
            indegrees[edges[i][0]]++;
            indegrees[edges[i][1]]++;
        }
        
        for(int i = 0;i < n;i++)
            if(indegrees[i] == 1)
                deque.add(i);
        
        while(n > 2){
            for(int i = deque.size();i > 0;i--){
                int node = (int)((LinkedList)deque).pollFirst();
                n--;
                for(int nei : adj.get(node)){
                    indegrees[nei]--;
                    if(indegrees[nei] == 1)
                        ((LinkedList)deque).offerLast(nei);
                }
            }
        }
        
        if(deque.size() == 0)
            deque.add(0);
        return deque;
    }
}