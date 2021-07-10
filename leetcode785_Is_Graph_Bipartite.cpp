class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int SIZE = graph.size();
        vector<int> colors(SIZE,0);
        
        function<bool(int,int)> dfs = [&](int node,int color) ->bool {
            colors[node] = color;
            for(int nei : graph[node]){
                if(colors[nei] == color)
                    return false;
                if(colors[nei] == 0 && !dfs(nei,-color))
                    return false;
            }
            return true;
        };
        
        for(int i = 0;i < SIZE;i++)
            if(colors[i] == 0 && !dfs(i,1))
                return false;
        
        return true;
    }
};

// https://tinyurl.com/mhbytdhx