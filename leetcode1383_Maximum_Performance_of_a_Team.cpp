class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int SIZE = speed.size(), MOD = 1e9 + 7;
        long long res = 0, totalSpeed = 0;
        vector<pair<int,int>> arrs;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0;i < SIZE;i++)
            arrs.emplace_back(efficiency[i],speed[i]);
        
        sort(arrs.begin(),arrs.end(),greater<pair<int,int>>());
        
        for(int i = 0;i < k;i++){
            pq.push(arrs[i].second);
            totalSpeed+= (long long)arrs[i].second;
            res = max(res,totalSpeed * (long long)arrs[i].first);
        }
        
        for(int i = k;i < SIZE;i++){
            if(pq.top() < arrs[i].second){
                totalSpeed+= arrs[i].second - pq.top();
                pq.pop();
                pq.push(arrs[i].second);
            }
            res = max(res,totalSpeed * (long long)arrs[i].first);
        }
        
        return res % MOD;
    }
};
// https://tinyurl.com/upp24cmb