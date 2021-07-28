class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        /*
        heap + sort. TC : O(N log N), SC : O(N)
        */
        const int SIZE = tasks.size();
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i = 0;i < SIZE;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(),tasks.end(),[](auto& lhs,auto& rhs){
            return lhs[0] < rhs[0];
        });
        
        for(int i = 0,startTime = 0;i < SIZE;i++){
            if(pq.empty())
                startTime = max(startTime,tasks[i][0]);
            while(i < SIZE && tasks[i][0] <= startTime)
                pq.emplace(tasks[i][1],tasks[i++][2]);
            i--;
            startTime+= pq.top().first;
            res.push_back(pq.top().second);
            pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

// https://tinyurl.com/3vs5f3ue