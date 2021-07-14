class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        const int SIZE = A.size();
        sort(A.begin(),A.end());
        vector<vector<int>> next(SIZE,vector<int>());
        vector<int> taken(SIZE,0);
        int res = 0;
        
        for(int i = 0;i < SIZE;i++){
            for(int j = i;j < SIZE;j++){
                int val = sqrt(A[i] + A[j]);
                if(val * val != A[i] + A[j])
                    continue;
                next[i].push_back(j);
                next[j].push_back(i);
            }
        }
        
        function<void(int,int)> dfs = [&](int idx,int count) {
            if(count == SIZE)
                res++;
            unordered_set<int> seen;
            
            for(int nei : next[idx]){
                if(taken[nei] || seen.count(A[nei]))
                    continue;
                taken[nei] = 1;
                seen.insert(A[nei]);
                dfs(nei,count + 1);
                taken[nei] = 0;
            }
        };
        
        for(int i = 0,pre = 1e9 + 1;i < SIZE;i++){
            if(pre == A[i])
                continue;
            taken[i] = 1;
            dfs(i,1);
            pre = A[i];
            taken[i] = 0;
        }
        
        return res;
    }
};
