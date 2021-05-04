class Solution {
public:
    int minJumps(vector<int>& arr) {
        // bfs
        const int SIZE = arr.size();
        if(SIZE == 1)
            return 0;
        unordered_map<int,vector<int>> mp;
        vector<int> visited(SIZE,false);
        for(int i = 0;i < SIZE;i++)
            mp[arr[i]].push_back(i);
        int step = 0;
        deque<int> q;
        q.push_back(0);
        visited[0] = true;
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                int idx = q.front();
                q.pop_front();
                if(idx + 1 < SIZE && !visited[idx + 1]){
                    visited[idx + 1] = true;
                    q.push_back(idx + 1);
                }
                if(idx - 1 >= 0 && !visited[idx - 1]){
                    visited[idx - 1] = true;
                    q.push_back(idx - 1);
                }
                if(mp.count(arr[idx])){
                    for(int n : mp[arr[idx]]){
                        if(!visited[n]){
                            visited[n] = true;
                            q.push_back(n);
                        }
                    }
                    mp.erase(arr[idx]);
                }
                if(visited[SIZE - 1])
                    return step + 1;
            }
            step++;
        }
        
        return SIZE;
    }
};