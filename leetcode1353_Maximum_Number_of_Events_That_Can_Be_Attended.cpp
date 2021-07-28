class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        /*
        heap + sort.
        TC : O(N logN), SC : O(N)
        */
        const int SIZE = events.size();
        events.push_back({100001,100002});
        priority_queue<int,vector<int>,greater<int>> pq;
        int res = 0, preTime = 0;
        
        sort(events.begin(),events.end(),[](auto& lhs,auto& rhs){
            if(lhs[0] != rhs[0])
                return lhs[0] < rhs[0];
            return lhs[1] < rhs[1];
        });
        
        for(vector<int>& e : events){
            int startTime = e[0], endTime = e[1];
            while(!pq.empty() && preTime < startTime){
                if(pq.top() >= preTime){
                    res++;
                    preTime++;
                }
                pq.pop();
            }
            pq.push(endTime);
            preTime = startTime;
        }
        
        return res;
    }
};

// https://tinyurl.com/4wet7far