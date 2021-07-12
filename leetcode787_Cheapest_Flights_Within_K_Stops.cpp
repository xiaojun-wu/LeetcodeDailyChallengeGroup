class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /*
        BFS + DP.
        use BFS to search each step.
        int each step, we update the minimum cost of to reach each city.
        if the minimum cost of a city is update(be lower), than add it into queue.
        We have to compare the cost of city before and after update.
        So we have to save the previous result to do the comparison.
        
        TC : (N * K)
        SC : (N)
        */
        vector<vector<pair<int,int>>> adjacents(n + 1,vector<pair<int,int>>());
        deque<int> q;
        vector<int> minCost(n + 1,INT_MAX);
        minCost[src] = 0;
        q.emplace_back(src);
        K++;
        
        for(vector<int>& f : flights)
            adjacents[f[0]].emplace_back(f[1],f[2]);
        
        while(!q.empty() && K){
            vector<int> prevals = minCost;
            for(int i = q.size();i > 0;i--){
                int city = q.front();
                q.pop_front();
                for(auto[nei,cost] : adjacents[city])
                    if(prevals[city] + cost < minCost[nei])
                        minCost[nei] = prevals[city] + cost;
            }
            for(int i = 0;i < n;i++)
                if(prevals[i] > minCost[i])
                    q.push_back(i);
            K--;
        }
        
        return minCost[dst] == INT_MAX?-1:minCost[dst];
    }
};
// https://tinyurl.com/fbjm23zj