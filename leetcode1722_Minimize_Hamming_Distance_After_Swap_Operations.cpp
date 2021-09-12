class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // find connect components
        const int SIZE = source.size();
        vector<int> visited(SIZE,0);
        vector<vector<int>> graph(SIZE,vector<int>());
        unordered_map<int,int> mp;
        int res = 0;
        
        for(vector<int>& e : allowedSwaps){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        function<void(int)> dfs = [&](int node) {
            visited[node] = 1;
            mp[source[node]]++;
            mp[target[node]]--;
            for(int nei : graph[node])
                if(!visited[nei])
                    dfs(nei);
        };
        
        for(int i = 0;i < SIZE;i++){
            if(!visited[i]){
                dfs(i);
                for(auto[val,count] : mp)
                    res+= abs(count);
                mp.clear();
            }
        }
        
        return res / 2;
    }
};