class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        /*
        two heap
        TC: O(N * logN), SC: O(N)
        */
        const int SIZE = arrival.size();
        set<int> idle;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy;
        vector<int> counts(k,0);
        vector<int> res;
        
        for(int i = 0;i < k;i++)
            idle.insert(i);
        
        for(int i = 0;i < SIZE;i++){
            int time = arrival[i], workload = load[i];
            while(!busy.empty() && busy.top().first <= time){
                idle.insert(busy.top().second);
                busy.pop();
            }
            int idx = i % k;
            auto it = idle.lower_bound(idx);
            if(it == idle.end())
                it = idle.begin();
            if(it == idle.end()) continue;
            counts[*it]++;
            busy.push({time + workload,*it});
            idle.erase(it);
        }
        
        int maxFreq = *max_element(counts.begin(),counts.end());
        
        for(int i = 0;i < k;i++)
            if(counts[i] == maxFreq)
                res.push_back(i);
        
        return res;
    }
};

// https://tinyurl.com/ythrbfa4