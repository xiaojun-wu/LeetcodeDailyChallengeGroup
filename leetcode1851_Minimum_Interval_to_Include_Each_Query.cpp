class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int SIZE = intervals.size(), QSIZE = queries.size();
        vector<int> res(QSIZE,-1);
        vector<pair<int,int>> arr;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        map<int,int> mp;
        
        for(int i = 0;i < QSIZE;i++)
            arr.emplace_back(queries[i],i);
        sort(arr.begin(),arr.end());
        sort(intervals.begin(),intervals.end(),[](auto& lhs,auto& rhs){
            return lhs[0] < rhs[0];
        });
        
        for(int i = 0,j = 0;i < QSIZE;i++){
            while(j < SIZE && intervals[j][0] <= arr[i].first){
                int len = intervals[j][1] - intervals[j][0] + 1;
                pq.emplace(intervals[j][1],len);
                mp[len]++;
                j++;
            }
            while(!pq.empty() && pq.top().first < arr[i].first){
                auto[end,len] = pq.top();
                pq.pop();
                mp[len]--;
                if(mp[len] == 0)
                    mp.erase(len);
            }
            if(!mp.empty())
                res[arr[i].second] = mp.begin()->first;
            if(j == SIZE && pq.empty())
                break;
        }
        
        return res;
    }
};

// https://tinyurl.com/ut4bvk3c