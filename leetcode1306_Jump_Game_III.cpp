class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // bfs
        const int SIZE = arr.size();
        if(arr[start] == 0)
            return true;
        vector<bool> visited(SIZE,false);
        deque<int> q;
        q.push_back(start);
        visited[start] = true;
        
        while(!q.empty()){
            int idx = q.front();
            q.pop_front();
            if(idx + arr[idx] < SIZE && !visited[idx + arr[idx]]){
                if(arr[idx + arr[idx]] == 0)
                    return true;
                visited[idx + arr[idx]] = true;
                q.emplace_back(idx + arr[idx]);
            }
            if(idx - arr[idx] >= 0 && !visited[idx - arr[idx]]){
                if(arr[idx - arr[idx]] == 0)
                    return true;
                visited[idx - arr[idx]] = true;
                q.emplace_back(idx - arr[idx]);
            }
        }
        
        return false;
    }
};
// https://tinyurl.com/2pmnbnt8