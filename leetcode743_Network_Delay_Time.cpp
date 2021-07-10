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
/*
[[2,1,1],[2,3,1],[3,4,1]]
4
2
[[1,2,1]]
2
1
[[1,2,1]]
2
2
[[2,1,1],[2,3,1],[3,4,1]]
4
2
[[1,2,1],[2,3,7],[1,3,4],[2,1,2]]
4
1
[[3,5,78],[2,1,1],[1,3,0],[4,3,59],[5,3,85],[5,2,22],[2,4,23],[1,4,43],[4,5,75],[5,1,15],[1,5,91],[4,1,16],[3,2,98],[3,4,22],[5,4,31],[1,2,0],[2,5,4],[4,2,51],[3,1,36],[2,3,59]]
5
5
[[1,2,1],[2,3,2],[1,3,2]]
3
1
[[4,2,76],[1,3,79],[3,1,81],[4,3,30],[2,1,47],[1,5,61],[1,4,99],[3,4,68],[3,5,46],[4,1,6],[5,4,7],[5,3,44],[4,5,19],[2,3,13],[3,2,18],[1,2,0],[5,1,25],[2,5,58],[2,4,77],[5,2,74]]
5
3
[[1,2,1],[2,1,3]]
2
2
*/