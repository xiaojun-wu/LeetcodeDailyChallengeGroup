class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacents(numCourses,vector<int>());
        vector<int> indegree(numCourses,0), res, empty;
        deque<int> q;
        
        for(vector<int>& p : prerequisites){
            adjacents[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i = 0;i < numCourses;i++)
            if(indegree[i] == 0)
                q.push_back(i);
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                int node = q.front();
                res.push_back(node);
                q.pop_front();
                for(int nei : adjacents[node]){
                    indegree[nei]--;
                    if(indegree[nei] == 0)
                        q.push_back(nei);
                }
            }
        }
        
        return res.size() == numCourses?res:empty;
    }
};