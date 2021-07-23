class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        const int SIZE = nums.size();
        vector<vector<int>> adjacents(SIZE,vector<int>());
        int isGCD[51][51] = {0};
        int mp[51] = {0};
        vector<int> visitedTime(SIZE + 1,-1);
        vector<int> res(SIZE,-1);
        
        for(vector<int>& edge : edges){
            adjacents[edge[0]].push_back(edge[1]);
            adjacents[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 1;i <= 50;i++)
            for(int j = i;j <= 50;j++)
                if(__gcd(i,j) == 1){
                    isGCD[i][j] = 1;
                    isGCD[j][i] = 1;
                }
        
        for(int i = 1;i <= 50;i++)
            mp[i] = -1;
        
        function<void(int,int)> dfs = [&](int node,int curtime) {
            int ret = SIZE;
            int oldNode = -1;
            oldNode = mp[nums[node]];
            visitedTime[node] = curtime;
            
            for(int i = 1;i <= 50;i++){
                if(mp[i] == -1) continue;
                if(isGCD[nums[node]][i] == 1)
                    if(visitedTime[ret] < visitedTime[mp[i]])
                        ret = mp[i];
            }
            
            if(ret != SIZE)
                res[node] = ret;
            mp[nums[node]] = node;
            for(int nei : adjacents[node])
                if(visitedTime[nei] == -1)
                    dfs(nei,curtime + 1);
            
            mp[nums[node]] = oldNode;
            
            return;
        };
        
        dfs(0,0);
        
        return res;
    }
};

// https://tinyurl.com/6vjjs3b4