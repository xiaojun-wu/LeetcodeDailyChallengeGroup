class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int SIZE = equations.size();
        vector<vector<pair<int,double>>> adjacents(SIZE * 2,vector<pair<int,double>>());
        unordered_map<string,int> mp;
        vector<double> res;
        vector<bool> visited(40,false);
        double curval = -1;
        int idx = 0;
        
        for(vector<string>& p : equations){
            if(!mp.count(p[0]))
                mp[p[0]] = idx++;
            if(!mp.count(p[1]))
                mp[p[1]] = idx++;
        }
        
        for(int i = 0;i < equations.size();i++){
            int idx1 = mp[equations[i][0]], idx2 = mp[equations[i][1]];
            adjacents[idx1].emplace_back(idx2,values[i]);
            adjacents[idx2].emplace_back(idx1,1/values[i]);
        }
        
        function<bool(int,int,double)> dfs = [&](int start,int end,double val) ->bool {
            if(start == end){
                curval = val;
                return true;
            }
            for(auto& p : adjacents[start]){
                if(!visited[p.first]){
                    visited[p.first] = true;
                    if(dfs(p.first,end,p.second * val))
                        return true;
                    visited[p.first] = false;
                }
            }
            return false;
        };
        
        for(int i = 0;i < queries.size();i++){
            int start = -1, end = -1;
            if(mp.count(queries[i][0]))
                start = mp[queries[i][0]];
            if(mp.count(queries[i][1]))
                end = mp[queries[i][1]];
            if(start == -1 || end == -1){
                res.push_back(-1);
                continue;
            }
            visited = vector<bool>(40,false);
            if(dfs(start,end,1))
                res.push_back(curval);
            else
                res.push_back(-1);
        }
        
        return res;
    }
};

// https://tinyurl.com/unz3pchs