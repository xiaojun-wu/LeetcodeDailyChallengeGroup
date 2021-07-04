class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjacents(numCourses,vector<int>());
        vector<vector<int>> pre(numCourses,vector<int>(numCourses,0));
        vector<int> indegree(numCourses,0);
        vector<bool> res;
        deque<int> q;
        
        for(vector<int>& p : prerequisites){
            adjacents[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        for(int i = 0;i < numCourses;i++)
            if(indegree[i] == 0)
                q.push_back(i);
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                int node = q.front();
                q.pop_front();
                for(int nei : adjacents[node]){
                    indegree[nei]--;
                    if(indegree[nei] == 0)
                        q.push_back(nei);
                    for(int j = 0;j < numCourses;j++)
                        pre[nei][j]|= pre[node][j];
                    pre[nei][node] = 1;
                }
            }
        }
        
        for(vector<int>& query : queries){
            if(pre[query[1]][query[0]])
                res.push_back(true);
            else
                res.push_back(false);
        }
        
        return res;
    }
};

// https://tinyurl.com/5dbrxda5