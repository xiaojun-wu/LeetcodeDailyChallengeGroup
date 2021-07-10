typedef pair<int,int> PII;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int visited[101] = {0};
        int dis[101];
        vector<vector<PII>> adjacents(n + 1,vector<PII>());
        int res = 0, count = 0;
        memset(dis,-1,sizeof(dis));
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        dis[k] = 0;
        
        for(vector<int>& t : times)
            adjacents[t[0]].emplace_back(t[1],t[2]);
        
        for(int i = 1;i <= n;i++)
            if(i != k)
                pq.push({INT_MAX,i});
        
        pq.push({0,k});
        
        while(!pq.empty() && count < n){
            auto [d,node] = pq.top();
            pq.pop();
            if(visited[node] == 1)
                continue;
            visited[node] = 1;
            // cout<<node<<" "<<d<<endl;
            res = max(res,d);
            if(d == INT_MAX)
                return -1;
            for(auto[nei,weight] : adjacents[node]){
                if(dis[nei] == -1 || dis[nei] > d + weight){
                    dis[nei] = d + weight;
                    pq.push({dis[nei],nei});
                }
            }
            count++;
        }
        
        return res == INT_MAX?-1:res;
    }
};
// https://tinyurl.com/supzn3hk