class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        const int SIZE = jobs.size();
        sort(jobs.begin(),jobs.end(),greater<int>());
        int workers[12] = {0};
        int res = INT_MAX;
        
        function<void(int,int)> dfs = [&](int idx,int curmax) {
            if(res <= curmax)
                return;
            if(idx == SIZE){
                res = min(res,curmax);
                return;
            }
            
            unordered_set<int> seen;
            
            for(int i = 0;i < k;i++){
                if(seen.insert(jobs[idx] + workers[i]).second){
                    workers[i]+= jobs[idx];
                    dfs(idx + 1,max(curmax,workers[i]));
                    workers[i]-= jobs[idx];
                }
            }
            return;
        };
        
        dfs(0,0);
        
        return res;
    }
};