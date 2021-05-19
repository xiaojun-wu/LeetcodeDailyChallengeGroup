class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        const int SIZE = edges.size();
        int res = 0;
        vector<bool> visited(SIZE,false);
        vector<unordered_map<int,int>> adjacents(SIZE,unordered_map<int,int>());
        vector<int> steps(SIZE,0);
        map<int,unordered_set<int>,greater<int>> heap;
        steps[0] = maxMoves;
        heap[maxMoves].insert(0);
        
        for(vector<int>& e : edges){
            adjacents[e[0]][e[1]] = e[2];
            adjacents[e[1]][e[0]] = e[2];
        }
        
        while(!heap.empty()){
            auto it = heap.begin();
            int step = it->first;
            for(int node : it->second){
                visited[node] = true;
                res++;
                for(auto it = adjacents[node].begin();it != adjacents[node].end();it++){
                    int nei = it->first, dis = it->second;
                    int colored = min(step,dis);
                    res+= colored;
                    adjacents[nei][node] = min(adjacents[nei][node],dis - colored);
                    if(!visited[nei] && step - colored > 0 && steps[nei] <= step - colored - 1){
                        if(heap.count(steps[nei]) && heap[steps[nei]].count(nei))
                            heap[steps[nei]].erase(nei);
                        heap[step - colored - 1].insert(nei);
                        steps[nei] = step - colored - 1;
                    }
                }
            }
            heap.erase(it);
        }
        
        return res;
    }
};
// https://tinyurl.com/xpp8r7px